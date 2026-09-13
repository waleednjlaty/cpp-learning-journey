#include <iostream>

using namespace std;
template <typename T>

class myVector
{

private:
  T *arr;
  int capacity;
  int size;
  void resize()
  {
    capacity *= 2;
    T *temp = new T[capacity];
    for (int i = 0; i < size; i++)
    {
      temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
  } // resize the dynamic array by doubling its capacity and copying the
    // elements to the new array

public:
  myVector()
  {
    capacity = 1;
    size = 0;
    arr = new T[capacity];
  } // constructor to initialize the dynamic array with a capacity of 1 and size
    // of 0

  myVector(int customization)
  {
    capacity = customization;
    size = 0;
    arr = new T[capacity];
  } // constructor to
  ~myVector()
  {
    delete[] arr;
  } // destructor to free the memory allocated for the dynamic array

  void push_back(T data)
  {
    if (capacity == size)
    {
      resize();
    }
    arr[size] = data;
    size++;
  } // add an element at the end of the dinamic array and resize the array if
    //  the capacity is full

  void pop_back()
  {
    if (size > 0)
      size--;
    else
      cout << "You don't possess ane element " << "\n";
  } // for delete an element from the end of the vector

  T get(int index)
  {
    if (index < size && index >= 0)
    {
      return arr[index];
    }
    return -1;
  } // for get an element at a specific index
  int getcapacity() { return capacity; } // get capacity of the dynamic array
  int getsize() { return size; }         // get size of the dynamic array
  void insert(int index, T data)
  {
    if (index < 0 || index > size)
    {
      cout << "Index out of bounds" << endl;
      return;
    }
    if (capacity == size)
    {
      resize();
    }
    for (int i = size; i > index; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[index] = data;
    size++;
  } // add element at a specific index and resize the array if the capacity is
    // full
  void erase(int index)
  {
    if (index < 0 || index >= size)
    {
      cout << "Index out of bounds" << endl;
      return;
    }
    for (int i = index; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }

    size--;
  } // erase any element from a specific index and shift the elements to fill
    // the gap

  int front()
  {
    if (size > 0)
    {
      return arr[0];
    }
    cout << "The array is empty" << "\n";
    return -1;
  } // show the first element of the array

  bool empty()
  {
    if (size == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  } // chack if the array is empty or not
  int back()
  {
    if (size > 0)
    {
      return arr[size - 1];
    }
    cout << "The array is empty" << "\n";
    return -1;
  } // show the last element of the array

  T &operator[](int index)
  {
    if (index < size && index >= 0)
    {
      return arr[index];
    }
    cout << "Index out of bounds" << endl;
    static int returnValue = -1; // Return a reference to a static variable to avoid dangling reference
    return returnValue;
  } // overload the [] operator to access elements at a specific index

  void clear()
  {
    size = 0;
  } // clear the array by setting the size to 0
};
int main()
{

  myVector<int> v; // test class
  v.push_back(1);
  v.push_back(2);
  v.pop_back();
  cout << v.getcapacity() << endl;
  cout << v.getsize() << endl;
  v.insert(0, 12);
  cout << v.get(0) << "\n";
  for (int i = 0; i < v.getsize(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
} // by Waleed Thanks for using my code and if you have any question please contact me on my email:waleed.njlaty@gmail.com