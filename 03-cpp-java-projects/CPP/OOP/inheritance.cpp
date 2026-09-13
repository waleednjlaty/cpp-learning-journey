#include <iostream>
using namespace std;
class Person
{
    int age;
    string name;

public:
    Person(int a, string n)
    {
        name = n;
        age = a;
    }
    void printinfo()
    {
        cout << "Your Name is : " << name << endl;
        cout << "Your age is : " << age << endl;
    }
};

int main()
{
    return 0;
}
