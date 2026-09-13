#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
class Student
{
private:
    string Name;
    int Mark;

public:
    Student(string n, int m)
    {
        Name = n;
        Mark = m;
    }
    Student()
    {
        cout << "Enter Your Name : ";
        cin >> Name;
        cout << "Enter Your Mark : ";
        cin >> Mark;
    }
    void ChackMark(Student s1, Student s2, Student s3)
    {

        if (s1.Mark > s2.Mark && s1.Mark > s3.Mark)
        {
            cout << "The better Student is " << s1.Name << "\nYour Mark is:" << s1.Mark << endl;
        }
        else if (s2.Mark > s1.Mark && s2.Mark > s3.Mark)
        {
            cout << "The better Student is " << s2.Name << "\nYour Mark is:" << s2.Mark << endl;
        }
        else if (s3.Mark > s1.Mark && s3.Mark > s2.Mark)
        {
            cout << "The better Student is " << s3.Name << "\nYour Mark is:" << s3.Mark << endl;
        }
    }
    friend int sum(Student s1, Student s2, Student s3);
};
int sum(Student s1, Student s2, Student s3)
{
    return s1.Mark + s2.Mark + s3.Mark;
}

int main()
{
    Student s1;
    Student s2;
    Student s3;
    cout << "Sum Marks : " << sum(s1, s2, s3) << endl;
    s1.ChackMark(s1, s2, s3);
    return 0;
}