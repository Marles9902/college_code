/*
 * This is the program file for the Student class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Student.h"
#include <iostream>

using namespace std;

//constructors
Student::Student(){
    studentID = "";
    firstName = "";
    lastName = "";
}

Student::Student(string aID, string aFirstName, string aLastName){
    studentID = aID;
    firstName = aFirstName;
    lastName = aLastName;
}

//Student::~Student()

//getters and setters
string Student::getStudentID(){
    return studentID;
}

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName(){
    return lastName;
}

void Student::setStudentID(string n){
    studentID = n;
}

void Student::setFirstName(string n){
    studentID = n;
}

void Student::setLastName(string n){
    studentID = n;
}

//functions
string Student::getInitial(){
    char fInit = firstName[0];
    char lInit = lastName[0];
    return to_string(fInit) + "." + to_string(lInit) + ".";
}

string Student::getFullName(){

}

string Student::getStudentID(){

}

string Student::getSchedule(){

}
