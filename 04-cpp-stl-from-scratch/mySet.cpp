#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};
template <typename T>
class MyStl
{
private:
    Node<T> *root;
    int sizeNode;
    Node<T> *insertNode(Node<T> *node, T val, bool &inserted)
    {
        if (node->data == nullptr)
        {
            inserted = true;
            return new Node<T>(val);
        }
        if (val < node->data)
        {
            node->left = insertNode(node->left, val, inserted);
        }
        else if (val > node->data)
        {
            node->right = insertNode(node->right, val, inserted);
        }
        else
        {
            insert = false;
        }

        return node;
    }
    bool searchHelper(Node<T> *node, T val)
    {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        if (val < node->data)
            return searchHelper(node->left, val);
        else
            return searchHelper(node->right, val);
    }
    Node<T> *findMin(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
    void inorderHelper(Node<T> *node)
    {
        if (node == nullptr)
            return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    Node<T> *deleteHelper(Node<T> *node, T val, bool &deleted)
    {
        if (node == nullptr)
        {
            deleted = false;
            return nullptr;
        }
        if (val < node->data)
        {
            node->left = deleteHelper(node->left, val, deleted);
        }
        else if (val > node->data)
        {
            node->right = deleteHelper(node->right, val, deleted);
        }
        else
        {
            deleted = true;
            if (node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right)
            {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node<T> *temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteHelper(node->right, temp->data, deleted);
            }
            return node;
        }
    }

public:
    MyStl()
    {
        root = nullptr;
        sizeNode = 0;
    }

    void insert(T val)
    {
        bool inserted = false;
        root = insertNode(root, val, inserted);
        if (inserted)
            sizeNode++;
    }
    void erase(T val)
    {
        bool deleted = false;
        root = deleteHelper(root, val, deleted);
        if (deleted)
            sizeNode--;
    }
    int find(T val)
    {
        return searchHelper(root, val) ? 1 : 0;
    }
    int size() { return sizeNode; }
    bool empty() { return sizeNode == 0; }
    void print()
    {
        inorderHelper(root);
        cout << endl;
    }
};
