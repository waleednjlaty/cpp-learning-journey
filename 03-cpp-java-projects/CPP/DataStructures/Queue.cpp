#include <iostream>
using namespace std;

// 1. تعريف العقدة (Node)
class Node
{
public:
    int data; // القيمة اللي بنخزنها (مثلاً رقم العميل)
    int priority;
    Node *next; // مؤشر (Pointer) يدلنا على العقدة اللي بعدها في الطابور

    // باني (Constructor) عشان يسهل علينا إنشاء عقدة جديدة وإعطائها قيمة مباشرة
    Node(int value, int priorit)
    {
        data = value;
        priority = priorit;
        next = nullptr; // في البداية، العقدة الجديدة ما تأشر على شيء
    }
};

// 2. تعريف الطابور (Queue)
class Queue
{
private:
    Node *front; // مؤشر المقدمة (من هنا نحذف / نخدم العميل)
    Node *rear;  // مؤشر الخلف (من هنا نضيف العميل الجديد)

public:
    // باني الطابور (Constructor)
    Queue()
    {
        // أول ما نفتح الطابور، بيكون فاضي، فالمؤشرات تأشر على اللاشيء (nullptr)
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int value, int priority)
    {
        Node *newNode = new Node(value, priority);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else if (newNode->priority > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << " Is Empty " << endl;
        }
        else
        {
            Node *temp;
            temp = front;
            front = temp->next;
            if (front == nullptr)
            {
                rear = nullptr; // نصفر الخلف لأن الطابور صار فاضي تماماً
            }
            delete (temp);
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Is Empty " << endl;
            return;
        }
        else
        {
            Node *current;
            current = front;
            while (current != nullptr)
            {
                cout << current->data << endl;
                current = current->next;
            }
        }
    }
    // --- هنا راح نكتب العمليات الأساسية قريباً ---
    // void enqueue(int value);  // دالة الإضافة
    // void dequeue();           // دالة الحذف
    // bool isEmpty();           // دالة التحقق إذا الطابور فاضي
    // void display();           // دالة لطباعة محتوى الطابور (للتجربة)
};

int main()
{
    // إنشاء كائن (Object) من نوع الطابور
    Queue myQueue;

    cout << "تم وضع حجر الأساس لمشروع الـ Queue بنجاح! 🏗️" << endl;

    return 0;
}