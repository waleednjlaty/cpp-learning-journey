#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
    int value;
    Node *next; // Pointer
};
Node *head = NULL;
// insert function
// الفانكشن المسؤولة عن الاضافة
void insertNode(int val)
{
    Node *newNode = new Node; // Create Box
    newNode->value = val;
    newNode->next = NULL; // تعيين المؤشر إلى NULL مرة واحدة هنا

    //------------------------------------------//
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head; // استخدام متغير محلي للمرور على القائمة
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node Inserted Successfully " << endl;
}
void Display()
{
    Node *currentNode;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        currentNode = head;
        while (currentNode != NULL)
        {

            cout << currentNode->value << endl;
            currentNode = currentNode->next;
        }
    }
}
int main()
{
    insertNode(20);
    insertNode(50);

    Display(); // استدعاء دالة العرض لرؤية النتيجة

    return 0;
}