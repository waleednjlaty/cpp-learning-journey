#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    /* data */
};

Node *Front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (Front == NULL && rear == NULL)
    {
        Front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (rear == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (Front == rear)
    {
        Node *temp = Front;
        Front = rear = NULL;
        delete (temp);
    }
    else
    {
        Node *temp = Front;
        Front = Front->next;
        delete (temp);
    }
}
int peek()
{
    if (Front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
    {
        return Front->data;
    }
}
void display()
{

    Node *temp = Front;
    if (temp == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    return 0;
}