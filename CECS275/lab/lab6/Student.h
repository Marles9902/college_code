/*
 * This is the header file for the Student class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student{
    public:
        Student();
        Student(string aID, string aFirstName, string aLastName);
        //~Student();
        string getStudentID();
        string getFirstName();
        string getLastName();
        void setStudentID(string n);
        void setFirstName(string n);
        void setLastName(string n);
        string getInitial();
        string getFullName();
        string getStudentID();
        string getSchedule();
        string toString();
    private:
        string studentID;
        string firstName;
        string lastName;
};

#endif