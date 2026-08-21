#include <iostream>
using namespace std;

class Animal
{
private:
    string name;
    int age;

public:
    Animal() {};
    Animal(string name, int age) : name(name), age(age) {};

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }

    void eat()
    {
        cout << "Nom Nom\n";
    }
    void sleep()
    {
        cout << "Zzzz\n";
    }

    void printInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Dog : public Animal
{
private:
    string breed;

public:
    Dog() {};
    Dog(string name, int age, string breed) : Animal(name, age), breed(breed) {}
    void bark() { cout << "Woof\n"; };
    void printDogInfo()
    {

        cout << getName();
        cout << getAge();
        cout << breed << endl;
    }
};

int main()
{
    Dog dog("Lucky", 3, "Golden");

    dog.eat();
    dog.sleep();
    dog.bark();
    dog.printDogInfo();
}