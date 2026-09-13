#include <iostream>
using namespace std;
template <typename K, typename V>

struct MapNode
{
    K key;
    V value;
    MapNode *right;
    MapNode *left;
    MapNode(K k, V v) : key(k), value(v), right(nullptr), left(nullptr) {}
};
template <typename K, typename V>
class myMap
{
private:
    MapNode<K, V> *root;
    int sizeNode;
    MapNode<K, V> *insertHelper(MapNode<K, V> *node, K key, V value, bool &isNew)
    {
        if (node == nullptr)
        {
            isNew = true;
            return new MapNode<K, V>(key, value);
        }

        if (key < node->key)
        {
            node->left = insertHelper(node->left, key, value, isNew);
        }
        else if (key > node->key)
        {
            node->right = insertHelper(node->right, key, value, isNew);
        }
        else
        {
            node->value = value;
            isNew = false;
        }
        return node;
    }
    MapNode<K, V> *findHelper(MapNode<K, V> *node, K k)
    {
        if (node == nullptr || node->key == k)
            return node;
        if (k < node->key)
            return findHelper(node->left, k);
        else
            return findHelper(node->right, k);
    }
    void inorderHelper(MapNode<K, V> *node)
    {
        if (node == nullptr)
            return;
        inorderHelper(node->left);
        cout << "[" << node->key << " : " << node->value << "]\n";
        inorderHelper(node->right);
    }

public:
    myMap()
    {
        root = nullptr;
        sizeNode = 0;
    }


    void insert(K k, V v)
    {
        bool isNew = false;
        root = insertHelper(root, k, v, isNew);
        if (isNew)
            sizeNode++;
    }

    V &operator[](K k)
    {
        MapNode<K, V> *node = findHelper(root, k);
        if (node != nullptr)
        {
            return node->value;
        }
     
        bool isNew = false;
        root = insertHelper(root, k, V(), isNew);
        sizeNode++;
        return findHelper(root, k)->value;
    }

    bool contains(K k)
    {
        return findHelper(root, k) != nullptr;
    }

    int size() { return sizeNode; }
    bool empty() { return sizeNode == 0; }

    void print()
    {
        inorderHelper(root);
    }
};
