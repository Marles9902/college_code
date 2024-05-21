/*
 * This is the header file that implements the Date class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef DATE_H
#define DATE_H

#include <string>

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        //Default constructor
        Date();
        //Overloaded constructor
        Date(int aMonth, int aDay, int aYear);

        //Getters and Setters
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);

        //Operator overloading
        Date operator<<(int aMonth, int aDay, int aYear);
        Date operator>>(int aMonth, int aDay, int aYear);
        Date operator++();
        Date operator--();
        Date operator+();
        Date operator-();

        //Functions
        //void listAllDates(int aYear);
        std::string toString();
};

#endif