#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void insertFront(Node *&head, int v)
{
    Node *n = new Node(v);
    n->next = head;
    head = n;
}
void insertBack(Node *&head, int v)
{
    Node *n = new Node(v);

    if (head == nullptr)
    {
        head = n;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        current = current->next;
    }

    current->next = n;
}
void insertAt(Node *&head, int index, int value)
{
    Node *n = new Node(value);

    Node *current = head;

    if (index == 0)
    {
        insertFront(head, value);
        return;
    }

    int newId = 0;

    while (current != nullptr && newId < index - 1)
    {
        current = current->next;
        newId++;
    }

    if (current == nullptr)
    {
        delete n;
        return;
    }

    n->next = current->next;
    current->next = n;
}

void deleteFront(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteBack(Node *&head)
{
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = nullptr;
    delete temp;
}

void deleteAt(Node *&head, int index)
{
    Node *current = head;

    if (index == 0)
    {
        deleteFront(head);
        return;
    }

    int newId = 0;

    while (current != nullptr && newId < index - 1)
    {
        if (current->next == nullptr)
        {
            deleteBack(head);
            return;
        }
        current = current->next;
        newId++;
    }

    Node *temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

bool search(Node *head, int value)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }
    return false;
}

void reverse(Node *&head)
{
    if (head == nullptr)
        return;
    Node *prev = nullptr;
    Node *current = head;
    Node *next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main()
{
    Node *head = nullptr;
    Node *n1 = new Node(10);
    head = n1;
    Node *n2 = new Node(10);
    Node *n3 = new Node(10);

    n1->next = n2;
    n2->next = n3;

    insertFront(head, 20);
    insertBack(head, 40);

    deleteFront(head);

    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}