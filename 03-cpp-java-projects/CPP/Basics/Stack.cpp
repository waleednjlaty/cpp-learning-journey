#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *Next;
};
Node *Head = NULL;
Node *Last;
void insertNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (Head == NULL)
    {
        Head = newNode;
        newNode->Next = NULL;
    }
    else
    {
        Last = Head;
        while (newNode->Next != NULL)
        {
            Last = newNode->Next;
        }
        Last->Next = newNode;
        newNode->Next = NULL;
    }
}
int pop()
{
    int Value;
    if (Head == NULL)
    {
        cout << "Stack UnderFlow" << endl;
    }
    Node *firstNode = Head;
    Value = firstNode->data;
    Head = Head->Next;
    delete (firstNode);
    return Value;
}
int Peek()
{
    if (Head == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        return Head->data;
    }
}
void Display()
{
    Node *current;
    if (Head == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        current = Head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->Next;
        }
    }
}
int main()
{

    return 0;
}