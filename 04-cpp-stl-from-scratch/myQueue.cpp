#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
}; // create Node class to store data and pointer to next node

template <typename T>
class myQueue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    myQueue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }; // create constructor to initialize front and rear pointers to nullptr and size to 0
    bool isEmpty()
    {
        return front == nullptr;
    } // check if the queue is empty
    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    } // add an element to the rear of the queue

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        size--;
    } // delete the front element of the queue

    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return front->data;
    } // show the front element of the queue without deleting it

    T top()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return front->data;
    } // also show the front element of the queue without deleting it

    int getSize()
    {
        return size;
    } // get the size of the queue
    T back()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return rear->data;
    } // show the rear element of the queue without deleting it
    ~myQueue()
    {
        while (!isEmpty())
        {
            pop();
        }
    }; //  destructor to delete all nodes in the queue after the queue is no longer needed
};
int main()
{
    // test the queue
    myQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element: " << q.peek() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size: " << q.getSize() << endl;
    q.pop();
    cout << "Front element after pop: " << q.peek() << endl;
    cout << "Size after pop: " << q.getSize() << endl;
    return 0;
}

// by Waleed Al-Njlat Thank you for using my code, if you have any questions or suggestions please contact me on my email: waleed.njlaty@gmail.com