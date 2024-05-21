/*
 * This is the main file that implements the Date class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include <iostream>
#include "Date.h"
#include "Date.cpp"

using namespace std;

//void listAllDates(int aYear);

void listAllDates(int aYear){
        int numDays[] = {};

        if(aYear % 4 == 0){
            int numDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        }
        else{
            int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        }

        for(int i = 1; i < 12; ++i){
            for(int j = 0; j < numDays[i]; ++j){
                cout << i << "/" << j << "/" << aYear << endl;
            }
        }
    }

int main(){
    int month, day, year;
    bool endLoop = false;
    do{
        //testing


        cout << "complete?: ";
        cin >> endLoop;
    }while(!endLoop);
return 0;
}