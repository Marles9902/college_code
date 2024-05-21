/*
 * This C++ program takes an int then continually modifies it depending on whether it is even or odd, until it is 1
 * CECS 275 - Spring 2022
 * @author Skye Rogers
 * @author Marwin Gonzales
 * version 1.0.0
 *
 */

 #include <iostream>
 using namespace std;

 int num;
 char ans;
 int numCount = 1;

 int main(){
    do{
        cout << "ENTER AN INTEGER BETWEEN 0 AND 1e6" << endl;
        cin >> num;
        cout << "n = " << num << endl;
        cout << num << ", ";
        while(num > 1){

            if((num % 2) != 0){                                                     //num is odd
                num = (num * 3) + 1;
                numCount++;
            }
            else{                                                                   //num is even
                num = (num / 2);
                numCount++;
            }
            cout << num;
            if(num > 1){
            cout << ", ";
            }
         }
        cout << endl << "There are " << numCount << " numbers" << endl;
        numCount = 1;                                                              //resetting the counter to 1
        cout << "WOULD YOU LIKE TO CONTINUTE THE PROGRAM? y/n" << endl;
        cin >> ans;
    }while(ans == 'y' | ans == 'Y');
    cout << "Thank you for using the program." << endl;
    return 0;
 }