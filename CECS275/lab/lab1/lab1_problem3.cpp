/*
 * This C++ program continuously asks the user for a string and displays the recursive reverse of that string
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
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
        string word;
        string half;
        string otherHalf;
        string chopped;
        int counter = 1;

        // ask the user to input a word
        cout << "ENTER A STRING: " << endl;
        cout << "s = ";
        cin >> word;

        while(word.length() > 2){
            // placeholder for the amount of letters in the word
            int num = word.length();

            // check if the word has odd or even amount of letters than split accordingly 
            // using .length() to get the correct substrings
            if(num % 2 == 1){       // use modulo to check if the word is odd
                half = word.substr(0, (word.length()/2) + 1);
                otherHalf = word.substr(word.length()/2 + 1);
            }
            else{
                half = word.substr(0, word.length()/2);
                otherHalf = word.substr(word.length()/2);
            }
            // add the first half to this placeholder for assembling the final word later 
            chopped += half;

            // reverse the latter half of the word 
            string reverse = "";
            // loop for each letter in the latter half, incrementing down by 1 
            for(int i=otherHalf.length()-1; i >=0; i--){
                reverse += otherHalf[i];
            }
            // display the recursive reverse 
            cout << "Step " << counter << ": " << chopped + reverse << endl;
            // replace the word with the reverse of the latter half
            word = reverse;
            // count up 1 for each step 
            counter += 1;
        }
        // ask user if they want to continue
        cout << endl << "WOULD YOU LIKE TO CONTINUE? (Y/N) ";
        cin >> ans;
        cout << endl;

    // condition for continuing or exiting
    }while(ans == 'y' || ans == 'Y');
    cout << "Thank you for using the program!" << endl;

    return 0;
}