#include <iostream>
#include <vector>

using namespace std;

class Notification
{
protected:
    string recipient;

public:
    Notification() {};
    Notification(string recipient) : recipient(recipient) {};

    virtual void send() = 0;
    virtual void printInfo() {};
    virtual ~Notification() {};
};

class EmailNotification : public Notification
{
protected:
    string emailAddress;

public:
    EmailNotification() {};
    EmailNotification(string recipient, string emailAddress) : Notification(recipient), emailAddress(emailAddress) {};
    void send()
    {
        cout << "Sending Email to " << emailAddress << endl;
    };
};
class PushNotification : public EmailNotification
{
protected:
    string deviceId;

public:
    PushNotification() {};
    PushNotification(string recipient, string emailAddress, string deviceId) : EmailNotification(recipient, emailAddress), deviceId(deviceId) {};

    void send()
    {
        cout << "Push Notification Email: " << emailAddress << " to " << deviceId << endl;
    }
};
int main()
{
    vector<Notification *> notifications;
    string email = "plokjok@gmail.com";
    EmailNotification *n1 = new EmailNotification("PlokJok", email);
    PushNotification p1("PlokJok", email, "iPhone 17");
    p1.send();
    n1->send();
}