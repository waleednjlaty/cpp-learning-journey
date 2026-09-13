#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = nullptr;
    } // constructor to initialize the node with a value and set the next pointer
      // to nullptr

}; // a node structure to hold the data and a pointer to the next node in the
   // stack

template <typename T>
class myStack
{
private:
    Node<T> *topstack;
    int size;

public:
    myStack()
    {
        topstack = nullptr;
        size = 0;
    } // provide a default value for the stack

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = topstack;
        topstack = newNode;
        size++;
    } // add an element to the top of the stack

    void pop()
    {
        if (topstack == nullptr)
            return;
        Node<T> *temp = topstack;
        topstack = topstack->next;
        delete temp;
        size--;
    } // remove the top element of the stack

    T top()
    {
        if (topstack == nullptr)
        {
            cout << "The Stack is Empty \n";
            return T();
        }
        return topstack->data;
    } // get the top element of the stack
    int getSize() { return size; }                 // get the size of the stack
    bool isEmpty() { return topstack == nullptr; } // check if the stack is empty

    void swap(myStack<T> &otherstack)
    {
        Node<T> *temp = topstack;
        topstack = otherstack.topstack;
        otherstack.topstack = temp;
        int tempSize = size;
        size = otherstack.size;
        otherstack.size = tempSize;
    } // swap the contents of two stacks
};
int main()
{

    // test stack
    myStack<int> stack;
    myStack<int> stack2;
    stack2.push(100);
    stack.push(12);
    cout << stack.top() << endl;
    stack.push(90);
    cout << stack.top() << endl;
    cout << stack.getSize() << endl;
    stack.pop();
    cout << stack.top() << endl;
    cout << stack.getSize() << endl;
    cout << stack.isEmpty() << endl;
    stack.swap(stack2);

    cout << stack.top() << endl; // should print 100 after swap
}