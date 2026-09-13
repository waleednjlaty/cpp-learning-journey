#include <iostream>
#include <string>

using namespace std;
template <typename T>
struct Node
{
  T data;
  Node *next;
  Node *back;
  Node(T value) : data(value), next(nullptr), back(nullptr) {}
};
template <typename T>
class myList
{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  myList()
  {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
  bool isEmpty() { return head == nullptr; }
  void push_front(T value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->back = newNode;
      head = newNode;
    }
    size++;
  }
  void push_back(T value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
      head = tail = newNode;
    }

    else
    {
      tail->next = newNode;
      newNode->back = tail;
      tail = newNode;
    }
    size++;
  }
  void print()
  {
    if (isEmpty())
    {
      cout << "The List is Empty !";
      return;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }
  void pop_back()
  {
    if (isEmpty())
    {
      cout << "The list is Empty ! " << endl;
      return;
    }
    if (head == tail)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      Node<T> *temp = tail;
      tail = tail->back;
      tail->next = nullptr;
      delete temp;
    }
    size--;
  }
  void pop_front()
  {
    if (isEmpty())
    {
      cout << "The list is Empty ! " << endl;
      return;
    }
    if (head == tail)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      Node<T> *temp = head;
      head = head->next;
      head->back = nullptr;
      delete temp;
    }
    size--;
  }
  T front()
  {
    if (isEmpty())
    {
      cout << "The list is Empty ! " << endl;
      return T();
    }
    return head->data;
  }
  T back()
  {
    if (isEmpty())
    {
      cout << "The list is Empty ! " << endl;
      return T();
    }
    return tail->data;
  }
  void print_reverse()
  {
    if (isEmpty())
    {
      cout << "The list is Empty ! " << endl;
      return;
    }
    Node<T> *temp = tail;
    while (temp != nullptr)
    {
      cout << temp->data << endl;
      temp = temp->back;
    }
  }
  void insert(int index, T value)
  {

    if (index < 0 || index > size)
    {
      cout << "Out of bounds!\n";
      return;
    }
    if (index == 0)
    {
      push_front(value);
      return;
    }
    if (index == size)
    {
      push_back(value);
      return;
    }

    Node<T> *newNode = new Node<T>(value);

    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
      temp = temp->next;
    }
    newNode->back = temp->back;
    newNode->next = temp;
    temp->back->next = newNode;
    temp->back = newNode;
    size++;
  }
  void erase(int index)
  {
    if (isEmpty() || index < 0 || index >= size)
    {
      cout << "List is empty or it's Out of bounds!\n";
      return;
    }
    if (index == 0)
    {
      pop_front();
      return;
    }
    if (index == size - 1)
    {
      pop_back();
      return;
    }
    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
      temp = temp->next;
    }
    temp->back->next = temp->next;
    temp->next->back = temp->back;
    delete temp;
    size--;
  }
  int search(T val)
  {
    if (isEmpty())
    {
      cout << "The list is Empty !" << endl;
      return -1;
    }

    Node<T> *temp = head;
    int index = 0;
    while (temp != nullptr)
    {
      if (temp->data == val)
      {
        return index;
      }
      temp = temp->next;
      index++;
    }
    return -1;
  }
  bool find(T val)
  {
    if (isEmpty())
    {
      cout << "The list is Empty !" << endl;
      return false;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
      if (temp->data == val)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
  void clear()
  {
    while (!isEmpty())
    {
      pop_front();
    }
  }
  int getSize()
  {
    return size;
  }
  ~myList()
  {
    clear();
  }
};