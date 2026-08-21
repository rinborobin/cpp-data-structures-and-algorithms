#include <iostream>
using namespace std;

float toKelvin(float cal)
{
    return cal + 273.15;
}
float toFahr(float cal)
{
    return (cal * 1.8) + 32;
}

int main()
{
    bool is_running = true;
    int user_input;
    float cal, kelvin, fahr;

    do
    {
        cout << "Select Conversion Calcius to: " << endl
             << "1. Fahrenheit" << endl
             << "2. Kelvin" << endl;
        cin >> user_input;
        if (user_input != 0)
        {
            cout << "Enter calcius: ";
            cin >> cal;
        }
        switch (user_input)
        {
        case 1:
            kelvin = toKelvin(cal);
            cout << cal << "C = " << kelvin << "K";
            break;
        case 2:
            fahr = toFahr(cal);
            cout << cal << "C = " << fahr << "F";
            break;
        case 0:
            is_running = false;
        default:
            break;
        }
    } while (is_running);
}