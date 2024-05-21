#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    // Date d;
    // Date bDay(6, 8, 2002);
    // cout << d.toString() << endl;
    // cout << bDay.toString() << endl;

    int day, month, year;
    bool isDone = false;

    // using made exception 
    while(!isDone){
        cout << "Enter your birthday: ";
        cin >> day >> month >> year;
        try{
            if(month > 12 || month < 1){
                throw Date::InvalidMonth();
            }
            if(day < 1 || day > 31){
                throw Date::InvalidDay();
            }
            if(year < 1 || year > 2022){
                throw Date::InvalidYear();
            }
            isDone = true;
            Date d(day, month, year);
            cout << d.toString() << endl;
        }catch(Date::InvalidMonth){
            cerr << "Invalid month" << endl;
        }catch(Date::InvalidDay){
            cerr << "Invalid day" << endl;
        }catch(Date::InvalidYear){
            cerr << "Invalid year" << endl;
        }
    }
    return 0;
}