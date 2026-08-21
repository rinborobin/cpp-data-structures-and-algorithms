#include <iostream>
using namespace std;

class Laptop
{
private:
    string brand;
    string cpu;
    int ram;
    int storage;
    int battery;
    bool powerOn;
    int brightness;

public:
    Laptop(string brand,
           string cpu,
           int ram,
           int storage,
           int battery,
           bool powerOn,
           int brightness) : brand(brand), cpu(cpu), ram(ram), storage(storage), battery(battery), powerOn(powerOn), brightness(brightness) {}
    void turnOn()
    {
        if (powerOn)
        {
            cout << "Laptop is already ON. \n";
        }
        else
        {
            powerOn = true;
            cout << "Turning Laptop ON.\n";
        }
    }
    void turnOff()
    {

        if (powerOn)
        {
            powerOn = false;
            cout << "Turning Laptop OFF. \n";
        }
        else
        {
            cout << "Laptop is already OFF.\n";
        }
    }
    void charge(int amount)
    {

        cout << "Battery Level: " << battery << "%  : Charged " << amount << "%\n";
        if (battery + amount < 100)
        {
            cout << "Battery Level: " << battery + amount << "%" << endl;
        }
        else
        {
            cout << "Battery Level: 100%" << endl;
        }
    };

    void upgradeRAM() {};

    void upgradeStorage() {};

    void useLaptop() {};

    void printSpec() {};
};

int main()
{
    Laptop myLaptop = Laptop("Lenovo", "Ryzen 9 8945HX", 32, 1028, 80, true, 30);
    myLaptop.turnOff();
    myLaptop.turnOff();
    myLaptop.turnOn();
    myLaptop.charge(30);
}