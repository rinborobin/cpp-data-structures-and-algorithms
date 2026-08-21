#include <iostream>
using namespace std;

class SmartDevice
{
protected:
    string deviceId_;
    string deviceName_;
    bool isOn_;

public:
    SmartDevice() {};
    SmartDevice(string deviceId, string deviceName, bool isOn) : deviceId_(deviceId), deviceName_(deviceName), isOn_(isOn) {};
    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual void printInfo() const = 0;

    virtual ~SmartDevice() {};
};

class SmartLight : public SmartDevice
{
private:
    int brightness_;

public:
    SmartLight() {};
    SmartLight(string deviceId, string deviceName, bool isOn, int brightness) : SmartDevice(deviceId, deviceName, isOn), brightness_(brightness) {};
    void turnOn() override { isOn_ = true; };
    void turnOff() override { isOn_ = false; };
    void printInfo() const override
    {
        cout << "Light" << endl;
        cout << "ID: " << deviceId_ << endl;
        cout << "Name: " << deviceName_ << endl;
        cout << "Status: ";
        if (isOn_)
            cout << "ON\n";
        else
            cout << "OFF\n";
        cout << "Brightness: " << isOn_ ? 0 : brightness_ << "%" << endl;
    }
};
int main()
{
    SmartLight light("L001", "Smart Light", false, 80);
    light.turnOn();
    light.printInfo();
}