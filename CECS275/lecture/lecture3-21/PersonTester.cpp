#include <iostream> 
#include "Person.h"

using namespace std;

void displayPerson(Person p){
    cout << p.getName() << endl;
}

int main()
{
    char name[5] = "Kobe";
    char anotherName[7] = "Jordan";
    Person p1(anotherName, 25);
    Person p2(name, 10);
    cout << "Jordan(25) is older than Kobe(10): " << (p1 > p2) << endl;
    cout << "Kobe age: " << int(p2) << endl;
    Person p3 = p2;
    //p2.ptr --> name 
    //p3.ptr --> name
    Person p4(p2);
    p1 = p2;
    cout << p4 << endl;
    p4 = p4 + 10;
    cout << p4 << endl;
    // p4 + 10 = p4;
    // cout << p4 << endl;
    p4 = 10 + p4;
    cout << p4 << endl;

    return 0;
}