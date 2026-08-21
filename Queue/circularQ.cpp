#include <iostream>
#include <vector>
using namespace std;

class Queue
{

private:
    static const int LENGTH = 5;
    int data[LENGTH];
    int _front;
    int _rear;
    int _size;

public:
    Queue()
    {
        _front = 0;
        _rear = 0;
        _size = 0;
    }

    void push(int v)
    {
        if (full())
        {
            cout << "Queue is full.\n";
            return;
        }
        data[_rear] = v;
        _rear = (_rear + 1) % LENGTH;
        _size++;
    }
    int front()
    {
        return data[_front];
    }
    int back()
    {
        return data[(_rear - 1 + LENGTH) % LENGTH];
    }
    bool empty()
    {
        return _size == 0;
    }
    bool full()
    {
        return _size == LENGTH;
    }
    int pop()
    {
        if (!empty())
        {
            int v = _front;
            _front = (_front + 1) % LENGTH;
            _size--;
            return data[v];
        }
        else
            cout << "Queue is empty.\n";
    }
    int size_()
    {
        return _size;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.front() << endl; // 10
    cout << q.back() << endl;  // 50
    cout << q.size_() << endl; // 5

    cout << q.pop() << endl; // 10
    cout << q.pop() << endl; // 20

    q.push(60);
    q.push(70);

    cout << q.front() << endl; // 30
    cout << q.back() << endl;  // 70
    cout << q.size_() << endl; // 5
}
