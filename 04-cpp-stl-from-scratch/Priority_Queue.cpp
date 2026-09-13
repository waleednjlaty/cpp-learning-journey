#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // added for runtime_error
using namespace std;
template <typename T>
class PriorityQueue
{
private:
    vector<T> heap;
    int getParent(int i) { return (i - 1) / 2; }
    int getLeft(int i) { return (2 * i) + 1; }
    int getRight(int i) { return (2 * i) + 2; }

    void heapifyUp(int i)
    {
        // check if the element is smaller than his parent, if yes then swap them
        while (i > 0 && heap[i] > heap[getParent(i)])
        {
            swap(heap[i], heap[getParent(i)]);
            i = getParent(i);
        }
    }
    void heapifyDown(int i)
    {
        int left = getLeft(i);
        int right = getRight(i);
        int index = i;
        // check if the left child is greater than the current node
        if (left < heap.size() && heap[left] > heap[index])
        {
            index = left;
        }
        // check if the right child is greater than the current node
        if (right < heap.size() && heap[right] > heap[index])
        {
            index = right;
        }
        // if the current node is not the largest, swap it with the largest child and heapify down
        if (index != i)
        {
            swap(heap[i], heap[index]);
            heapifyDown(index);
        }
    }

public:
    void push(T val)
    {
        heap.push_back(val);        // add the new element to the end of the heap
        heapifyUp(heap.size() - 1); // add the new element to the end of the heap and heapify up
    } // add the new element to the end of the heap and heapify up
    void pop()
    {
        if (empty())
        {
            throw runtime_error("Priority queue is empty");
        }

        swap(heap.front(), heap.back()); // replace the root with the last element
        heap.pop_back();                 // remove the last element from the heap
        heapifyDown(0);                  // heapify down the root element
    }
    T top()
    {
        if (empty())
        {
            throw runtime_error("Priority queue is empty");
        }
        return heap[0]; // return the root element
    }
    bool empty()
    {
        return heap.empty(); // return true if the heap is empty, false otherwise
    }
    int size()
    {
        return heap.size(); // return the size of the heap
    }
};