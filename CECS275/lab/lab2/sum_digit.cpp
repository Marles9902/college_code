/*
 * This program continuously asks the user for a positive integer and display the sum of all the digits of the number
 * CECS 275 - Spring 2022   
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    // variable for do-while continuing
    char ans;
    // do-while loop to ask the user if they want to use the program again
    do{
        // variables 
        string number;
        unsigned int num = 0;

        // ask the user to input a positive integer
        cout << "Enter a positive integer: ";
        cin >> number;
        
        // if statements checking if the integer is actually positive
        if(number[0] == '0'){       // if 0, try again 
            cout << "You have entered zero. Please try again!" << endl;
        }else if(number[0] == '-'){         // if negative, try again 
            cout << "You have entered a negative number. Please try again!" << endl;
        }else{      // if positive, execute 
            // output the positive integer user has entered
            cout << "You have entered " << number << endl;
            // since input is a string, for each character in input
            for(char ch : number){ 
                // add to num variable 
                num = num + (ch - '0');
            }
            // output the result
            cout << "The sum of all digits of " << number << " is " << num << endl;
        }
        // ask the user if they want to continue
        cout << endl << "WOULD YOU LIKE TO CONTINUE? (Y/N) ";
        cin >> ans;
        cout << endl;

    // condition for continuing or exiting
    }while(ans == 'y' || ans == 'Y');
    cout << "Thank you for using the program!" << endl;
    return 0;
}