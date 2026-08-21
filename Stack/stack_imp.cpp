#include <iostream>
using namespace std;

class Stack
{
private:
    int data[100];
    int top_;

public:
    Stack() { top_ = -1; };
    void push(int value)
    {
        top_++;
        data[top_] = value;
    };
    int pop()
    {
        return data[top_--];
    };
    int top()
    {
        return data[top_];
    };
    bool empty()
    {
        return top_ >= 0;
    };
    bool full()
    {
        return top_ > 99;
    };
    int size()
    {
        return top_ + 1;
    };
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl; // 30

    s.pop();

    cout << s.top() << endl; // 20
}