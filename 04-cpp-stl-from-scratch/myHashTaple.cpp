#include <iostream>
#include <string>
#include <functional>

using namespace std;
template <typename K, typename V>
struct HashNode
{
    K key;
    V value;
    HashNode *next;

    HashNode(K k, V v) : key(k), value(v), next(nullptr) {}
};

template <typename K, typename V>
class MyHashTable
{
    HashNode<K, V> **table;
    int capacity;
    int Count;
    int getHashIndex(const K &key) const
    {
        return hash<K>{}(key) % capacity;
    }

public:
    MyHashTable(int cap = 10)
    {
        capacity = cap;
        count = 0;
        table = new HashNode<K, V> *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }
    ~MyHashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            HashNode<K, V> *current = table[i];
            while (current != nullptr)
            {
                HashNode<K, V> *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    void insert(const K &key, const V &val)
    {
        int index = getHashIndex(key);
        HashNode<K, V> *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = val;
            }
            current = current->next;
        }
        HashNode<K, V> *newNode = new HashNode<K, V>(key, val);
        newNode->next = table[index];
        table[index] = newNode;
        Count++;
    }
    bool erase(const K &key)
    {
        int index = getHashIndex(key);
        HashNode<K, V> *current = table[index];
        HashNode<K, V> *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; // حذف العنصر الأول في السلسلة
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                Count--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    bool contains(const K &key) const
    {
        int index = getHashIndex(key);
        HashNode<K, V> *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
                return true;
            current = current->next;
        }
        return false;
    }
    V &operator[](const K &key)
    {
        int index = getHashIndex(key);
        HashNode<K, V> *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        insert(key, V());
        return table[index]->value;
    }
    int size() const { return Count; }
    bool empty() const { return Count == 0; }
    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket [" << i << "]: ";
            HashNode<K, V> *current = table[i];
            while (current != nullptr)
            {
                cout << "(" << current->key << " : " << current->value << ") -> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }
    }
};
