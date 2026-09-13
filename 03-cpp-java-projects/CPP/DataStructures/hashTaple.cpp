#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{

    unordered_map<string, long long int> person;

    person["waleed"] = 5325;
    if (person.find("waleed") != person.end())
    {
        cout << person["waleed"];
    }
    return 0;
}