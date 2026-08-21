#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
    string password = "Hello123213";
    int result = 0;
    if (password.length() >= 8)
    {
        result += 1;
    }
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            result += 1;
            break;
        }
    }
    for (int i = 0; i < password.length(); i++)
    {
        if (islower(password[i]))
        {
            result += 1;
            break;
        }
    }

    for (int i = 0; i < password.length(); i++)
    {

        if (ispunct(password[i]))
        {
            result += 1;
            break;
        }
    }
    for (int i = 0; i < password.length(); i++)
    {

        if (isdigit(password[i]))
        {
            result += 1;
            break;
        }
    }

    if (result <= 2)
        cout << "Weak" << endl;
    else if (result <= 4)
        cout << "Mid" << endl;
    else
        cout << "Strong" << endl;
}