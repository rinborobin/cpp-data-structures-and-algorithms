#include <iostream>
using namespace std;

int main()
{
    char op;
    int num1, num2, result;
    cout << "Calculator" << endl;
    cout << "Enter first number, operation, second number: ";
    cin >> num1 >> op >> num2;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        cout << "Result: " << result;
        break;
    case '-':
        result = num1 - num2;
        cout << "Result: " << result;
        break;
    case '*':
        result = num1 * num2;
        cout << "Result: " << result;
        break;
    case '/':
        result = num1 / num2;
        cout << "Result: " << result;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}