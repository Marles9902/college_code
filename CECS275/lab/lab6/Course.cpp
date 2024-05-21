/*
 * This is the program file for the Course class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Course.h"
#include <iostream>

using namespace std;

//constructors
Course::Course(){
    courseNumber = "";
    courseName  = "";
    courseTime = "";
    courseSemester = "";
}

Course::Course(string aNumber, string aName, string aTime, string aSemester){
    courseNumber = aNumber;
    courseName  = aName;
    courseTime = aTime;
    courseSemester = aSemester;
}

//Course::~Course()

//getters and setters
string Course::getCourseNumber(){
    return courseNumber;
}

string Course::getCourseName(){
    return courseName;
}

string Course::getCourseTime(){
    return courseTime;
}

string Course::getCourseSemester(){
    return courseSemester;
}

void Course::setCourseNumber(string s){
    courseNumber = s;
}

void Course::setCourseName(string s){
    courseName = s;
}

void Course::setCourseTime(string s){
    courseTime = s;
}

void Course::setCourseSemester(string s){
    courseSemester = s;
}

//functions
string Course::toString(){
    return courseSemester + " " + courseName + " " + courseNumber + ": " + courseTime;
}