/*
 * This is the header file for the Course class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course{
    public:
        Course();
        Course(string aNumber, string aName, string aTime, string aSemester);
        //~Course();
        string getCourseNumber();
        string getCourseName();
        string getCourseTime();
        string getCourseSemester();
        void setCourseNumber(string s);
        void setCourseName(string s);
        void setCourseTime(string s);
        void setCourseSemester(string s);
        string toString();
    private:
        string courseNumber;
        string courseName;
        string courseTime;
        string courseSemester;
};

#endif