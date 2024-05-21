/*
 * This is the .cpp file that implements the Date class' attributes
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Date.h"
#include <iostream>

using namespace std;

Date::Date():Date(1, 1, 2000){}

Date::Date(int aMonth, int aDay, int aYear){
    month = aMonth;
    day = aDay;
    year = aYear;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}

int Date::getYear() const{
    return year;
}

void Date::setMonth(int m){
    month = m;
}

void Date::setDay(int d){
    day = d;
}

void Date::setYear(int y){
    year = y;
}

// void Date::listAllDates(int aYear){
//     int numDays[] = {};

//     if(aYear % 4 == 0){
//         int numDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     }
//     else{
//         int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     }

//     for(int i = 0; i < 12; ++i){
//         for(int j = 1; j < numDays[i]; ++j){
//             cout << i << "/" << j << "/" << aYear << endl;
//         }
//     }
// }

string Date::toString(){
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

Date operator<<(){

}

Date operator>>(){

}

Date operator++(int nd){
    int nd = d + 1
    return Date::setDay(nd);
}

Date operator--(int nd){
    int nd = d - 1;
    return Date::setDay(nd);
}

Date operator+(int nd){
    int nd = d + 1
    return Date::setDay(nd);
}

Date operator-(int nd){
    int nd = d - 1;
    return Date::setDay(nd);
}