#include <iostream>
using namespace std;

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

struct Person
{
    string name;
    int age;
    bool operator<(const Person &rhs) const { return this->age < rhs.age; }
};

int main()
{
}