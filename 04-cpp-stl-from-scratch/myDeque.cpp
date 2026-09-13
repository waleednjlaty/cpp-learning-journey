#include <iostream>
using namespace std;

template <typename T>

class myDeque
{
private:
    T *arr;
    int capacity;
    int frontIdx;
    int count;
    void resize()
    {
        int newCapacity = 2 * capacity;
        T *newArr = new T[newCapacity];

        for (int i = 0; i < count; i++)
        {
            newArr[i] = arr[(frontIdx - i) % capacity];
        }
        delete[] arr;
        arr = newArr;
        frontIdx = 0;
        capacity = newCapacity;
    }

public:
    myDeque(int inticapa = 4)
    {
        capacity = inticapa;
        frontIdx = 0;
        count = 0;
        arr = new T[capacity];
    }
    ~myDeque()
    {
        delete[] arr;
    }

    void push_back(T val)
    {
        if (capacity == count)
            resize();

        int backIdx = (frontIdx + count) % capacity;
        arr[backIdx] = val;
    }
    void push_front(T val)
    {
        if (capacity == count)
            resize();
        frontIdx = (frontIdx - 1 + capacity) % capacity;
        arr[frontIdx] = val;
    }
    void pop_back()
    {
        if (empty())
            throw out_of_range("The Deque is Empty !");
        count--;
    }
    void pop_front()
    {
        if (empty())
            throw out_of_range("The Deque is Empty !");
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }
    bool empty()
    {
        return count == 0;
    }
    int size() { return count; }
    void clear()
    {
        count = 0;
        frontIdx = 0;
    }
    T &front()
    {
        if (empty())
            throw out_of_range("Deque is empty!");
        return arr[frontIdx];
    }

    T &back()
    {
        if (empty())
            throw out_of_range("Deque is empty!");
        return arr[(frontIdx + count - 1) % capacity];
    }
    T &operator[](int index)
    {
        if (index < 0 || index >= count)
            throw out_of_range("Index out of bounds!");
        return arr[(frontIdx + index) % capacity];
    }
};
