#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertFront(int value)
    {
        Node *node = new Node(value);

        node->next = head;

        if (head != nullptr)
        {
            head->prev = node;
        }
        head = node;
    }

    void insertBack(int value)
    {
        if (head == nullptr)
        {
            insertFront(value);
            return;
        }
        Node *node = new Node(value);
        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
    }

    void deleteFront()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    void deleteBack()
    {
        if (head == nullptr)
            return;
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        Node *temp = current->next;
        current->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    void insertAt(int index, int value)
    {
        // your code
    }

    void printForward()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void printBackward()
    {
        // We'll implement this later
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    cout << "Forward: ";
    list.printForward();

    return 0;
}