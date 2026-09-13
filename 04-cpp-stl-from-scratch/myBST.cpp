#include <iostream>
using namespace std;
template <typename T> struct Node {
  T data;
  Node *right;
  Node *left;
  Node(T val) {
    data = val;
    right = nullptr;
    left = nullptr;
  }
}; // belid the Node structure
template <typename T> class myBST {
private:
  Node<T> *root;
  Node<T> *insertHelper(Node<T> *node, T val) {
    if (node == nullptr) {
      return new Node<T>(val);
    } // if the node is null, create a new node with the value

    if (val < node->data) {
      node->left = insertHelper(node->left, val);
    } // if the value is less than the node's data, insert it in the left
      // subtree
      
    else if (val > node->data) {
      node->right = insertHelper(node->right, val);
    } // if the value is greater than the node's data, insert it in the right
      // subtree

    return node;
  } // insertHelper function to insert a new node in the BST
  bool searchHelper(Node<T> *node, T val) {
    if (node == nullptr) {
      return false;
    }
    if (node->data == val) {
      return true;
    }

    if (val < node->data) {
      return searchHelper(node->left, val);
    } // if the value is less than the node's data, search in the left subtree

    else {
      return searchHelper(node->right, val);
    } // if the value is greater than the node's data, search in the right
      // subtree

  } // searchHelper function to search for a value in the BST
  void inorderHelper(Node<T> *node) {
    if (node == nullptr)
      return;

    inorderHelper(node->left);  // inorderHelper function to print the BST in
                                // inorder traversal

    cout << node->data << " ";  // print the node's data

    inorderHelper(node->right); // inorderHelper function to print the BST in
                                // inorder traversal

  } // inorderHelper function to print the BST in inorder traversal
    // left->root->right

  Node<T> *findMin(Node<T> *node) {
    while (node->left != nullptr) {
      node = node->left;
    } // findMin function to find the minimum value in the BST

    return node;

  } // findMin function to find the minimum value in the BST
  Node<T> *deleteHelper(Node<T> *node, T val) {
    if (node == nullptr)
      return nullptr;

    if (val < node->data) {
      node->left = deleteHelper(node->left, val);
    } else if (val > node->data) {
      node->right = deleteHelper(node->right, val);
    } else {
      if (node->left == nullptr) {
        Node<T> *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node<T> *temp = node->left;
        delete node; // delete the node and return the left child
        return temp;
      }
      Node<T> *temp =
          findMin(node->right); // find the minimum value in the right subtree
      node->data = temp->data;
      node->right = deleteHelper(
          node->right,
          temp->data); // delete the minimum value in the right subtree
    }
    return node;
  }

public:
  myBST() { root = nullptr; }
  void insert(T val) {
    root = insertHelper(root, val);
  } // insert function to insert a new node in the BST
  void inorder() {
    inorderHelper(root);
    cout << endl;
  } // inorder function to print the BST in inorder traversal
  bool search(T val) {
    return searchHelper(root, val);
  } // search function to search for a value in the BST
  void deleteNode(T val) {
    root = deleteHelper(root, val);
  } // deleteNode function to delete a node in the BST
};
