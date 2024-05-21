/*
 * This C++ program takes a string in a text file and outputs its most repeated substring at length N into a separate text file
 * CECS 275 - Spring 2022
 * @author Skye Rogers
 * @author Marwin Gonzales
 * version 1.0.0
 */

//include initializations
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

//variable initializations
int i, j, count;
int N = 3;

int main(){
    ifstream infile;
    ofstream outfile;

    //opening both files to be read from/written to
    infile.open("input.txt");
    outfile.open("result.txt");

    //file open error catcher
    if(!infile){
        cerr << "File open error." << endl;
        exit(1);
    }

    //main variable initialization
    string myStr;
    string mySubStr;

    //while inside the input.txt file
    while(infile >> myStr){
        for(i = 0; i < myStr.length() - 2; ++i){        //for loop counting up to the length of our input.txt string
            string mySubStr = myStr.substr(i, N);       //separate the string into N(3) length substrings and cut off substrings less than N
            //cout << mySubStr << endl;                 //output mySubStr for testing
            outfile << mySubStr << " ";
        }
    }
}