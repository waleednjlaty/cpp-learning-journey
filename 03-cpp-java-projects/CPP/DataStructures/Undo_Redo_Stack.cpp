#include <iostream>
#include <string>

using namespace std;

// 1. The Node (plate) that you created
struct Node
{
    string data;
    Node *next;
};

// 2. The Stack (table) class built from scratch
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(string text)
    {
        Node *newNode = new Node;
        newNode->data = text;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            // Silent so it doesn't bother us inside the program
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek()
    {
        if (top == nullptr)
        {
            return "";
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

// A simple interface to display text
void showStatus(string text)
{
    cout << "\n===============================" << endl;
    cout << "Current Text: " << (text.empty() ? "[Empty]" : text) << endl;
    cout << "===============================" << endl;
}

int main()
{
    Stack undoStack;
    Stack redoStack;
    string currentText = "";
    string input;
    int choice;

    while (true)
    {
        showStatus(currentText);
        cout << "1. Write a new word\n2. Undo\n3. Redo\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the word: ";
            cin >> input;

            // The addition code that you understood
            undoStack.push(currentText);
            currentText = currentText + (currentText.empty() ? "" : " ") + input;

            // The code to destroy the old future that you wrote
            while (!redoStack.isEmpty())
            {
                redoStack.pop();
            }
        }
        else if (choice == 2)
        {
            // Your Undo code
            if (undoStack.isEmpty())
            {
                cout << "Nothing to undo!" << endl;
            }
            else
            {
                redoStack.push(currentText);
                currentText = undoStack.peek();
                undoStack.pop();
            }
        }
        else if (choice == 3)
        {
            // Your Redo code
            if (redoStack.isEmpty())
            {
                cout << "Nothing to redo!" << endl;
            }
            else
            {
                undoStack.push(currentText);
                currentText = redoStack.peek();
                redoStack.pop();
            }
        }
        else if (choice == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        system("cls");
    }

    return 0;
}