#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    int data[100];
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
        if (_size == 100)
        {
            cout << "Queue is full.\n";
            return;
        }
        data[_rear] = v;
        _rear++;
        _size++;
    }
    int first()
    {
        return data[_front];
    }
    int back()
    {
        return data[_rear - 1];
    }
    bool empty()
    {
        return _front >= _rear;
    }
    int pop()
    {
        if (!empty())
            return data[_front++];
        else
            cout << "Queue is empty.\n";
    }
    int size()
    {
        return _rear - _front;
    }
};

int main()
{
    Queue queue;
    queue.push(10);
    queue.push(20);
    queue.pop();
    queue.push(6);
    cout << queue.first() << endl;
    cout << queue.back() << endl;
}
