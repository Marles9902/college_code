#include "Date.h"

using namespace std;

Date::Date(){

}

Date::Date(int aDay, int aMonth, int aYear){
    day = aDay;
    month = aMonth;
    year = aYear;
}

string Date::toString(){
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

int Date::getDay() const{
    return day;
}

void Date::setMonth(int aMonth){
    month = aMonth;
}

void Date::setYear(int aYear){
    year = aYear;
}

void Date::setDay(int aDay){
    day = aDay;
}