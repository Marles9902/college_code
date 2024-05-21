#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

class Person{
    private:
        char* name;
        int age;
    public:
        friend ostream& operator<<(ostream& os, const Person p){
            cout << "NAME: " << p.name << endl;
            cout << "AGE: " << p.age << endl;
            return os;
        }
        // const in the beginning will not let you execute p4 + 10 = p4
        const Person& operator+(int mAge){
            this->age += mAge;
            return *this;
        }
        friend const Person& operator+(int mAge, const Person& p){
            Person* pn = new Person(p.name, p.age + mAge);
            return *pn;
        }
        bool operator>(const Person& other){
            return this->age > other.age;
        }
        // friend bool operator>(const Person& p1, const Person& p2){      // should be overloaded as member function
        //     return p1.age > p2.age;
        // }

        operator int(){
            return this->age;
        }
        // default constructor
        Person(){
            // cout << "CALLING DEFAULT CONSTRUCTOR" << endl;
            name = nullptr;
            age = 0;
        }
        // overloaded Construtor
        Person(char* mName, int mAge){
            // cout << "CALLING OVERLOADED CONSTRUCTOR" << endl;
            name = new char[strlen(mName) + 1];
            strcpy(name, mName);
            age = mAge;
        }
        // copy constructor
        Person (const Person& other){
            // cout << "CALLING COPY CONSTRUCTOR" << endl;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            age = other.age;
        }
        // overloaded = operator
        Person& operator=(const Person &other){
            // cout << "CALLING ASSIGNMENT OPERATOR" << endl;
            if(this != &other){
                if(name != nullptr){
                    delete[] name;
                }
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
                age = other.age;
            }
            return *this;
        }
        // destructor
        ~Person(){
            // cout << "CALLING DESTRUCTOR" << endl;
            delete [] name;
        }
        char* getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }
};

#endif