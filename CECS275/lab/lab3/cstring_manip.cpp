/*
 * This program implements functions that manipulate strings by either reversing 
 * or concatenating two strings within a max length
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// function that reverses a character string
void reverse(char s[]){
    for(int i = 0; i < (strlen(s) / 2); i++){   // only loop for half of the amount of characters in string
        char temp = s[i];                       // temp is assigned the first letter of the string
        s[i] = s[strlen(s) - i - 1];            // first placement is assigned the last letter of the string
        s[strlen(s) - i - 1] = temp;            // last letter is replaced by temp which is the first letter of the string
    }
    cout << s << endl;                          // display result
}

// function that concatenates the strings a and b within a maximum amount of letters
void concat(const char a[], const char b[], char result[], int result_maxlength){
    // this is here as a condition to check if the second string is actually needed
    char check[100];
    strncpy(check, a, sizeof(check));

    if(result_maxlength <= strlen(check)){          // if the maxlength given is <= to the length of the first string
        char str1[100];
        str1[result_maxlength] = '\0';
        strncpy(str1, a, result_maxlength);         // copy the first string given to a blank one and stop at maxlength
        cout << str1 << endl;
    }else if(result_maxlength >= strlen(check)){    // if the maxlength given is >= to the length of the first string
        char str1[result_maxlength];
        char str2[result_maxlength];

        strncpy(str1, a, result_maxlength);         // copy given strings to new strings
        strncpy(str2, b, result_maxlength);

        int limit = result_maxlength - strlen(str1);    // calculate the maxlength of the concatenated string

        strncat(str1, str2, limit);                 // concatenate
        cout << str1 << endl;                       // display result
    }
}

int main(){
    // output for reverse problem
    char str[] = "";
    cout << "Enter a word to reverse: ";
    cin >> str;
    cout << endl;
    cout << "RESULT: " << endl;    
    reverse(str);
    
    cout << "---------------------------------------------------------" << endl;

    //output for concatenate problem
    char str1[100];
    char str2[100];
    char res[] = " ";
    int length;

    cout << "Enter words to concatenate below" << endl;;
    cout << "Enter first word: ";
    cin >> str1;
    cout << "Enter second word: ";
    cin >> str2;
    cout << "Enter max length of result: ";
    cin >> length;
    cout << "concatentating " << '"' << str1 << '"' << " and " << '"' << str2 << '"' << " with max length of " << length << "..." << endl;
    cout << endl;
    cout << "RESULT: " << endl;
    concat(str1, str2, res, length);

    


    return 0;
}