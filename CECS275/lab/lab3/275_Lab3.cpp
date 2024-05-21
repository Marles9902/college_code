/*
 * This C++ program takes a list of numbers in a text file and outputs each numbers' frequency into a separate text file
 * CECS 275 - Spring 2022
 * @author Skye Rogers
 * @author Marwin Gonzales
 * version 1.0.0
 */

//include initializations
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int x = 0;

void bubbleSort(vector<int> myVec);
void mySortSwap(int, int);
int myFrequency(vector<int> myVec, int s, int x);

int main(){
    ifstream infile;
    ofstream outfile;

    vector<int> myVec;
    int x;

    //opening both files to be read from/written to
    infile.open("data.txt");
    outfile.open("frequency.txt");

    //file open error catcher
    if(!infile){
        cerr << "File open error." << endl;
        exit(1);
    }

    bubbleSort(myVec);

    //while(myVec >> infile){                                           //FIX
        mySelector(myVec, x);
        myFrequency(myVec, myVec.size(), x);
    //}

    return 0;
}


void bubbleSort(vector<int> myVec){
    for(int i = 0; i < myVec.size(); ++i){
        for(int j = 0; j < myVec.size(); ++j){
            if(myVec[i] < myVec[j]){
                mySortSwap(myVec[i], myVec[j]);
            }
        }
    }
}

void mySortSwap(int t, int y){
    int z = t;
    t = y;
    y = z;
}

int myFrequency(vector<int> myVec, int s, int x){                   //s = size of myVec, x = num to be checked
    int counter;
    for(int i = 0; i < s; ++i){
        if(myVec[i] == x){
            ++counter;
        }
    }
    //return counter;
}

int mySelector(vector<int> myVec, int x){                           //b = last num to be counted
    for(int i = 0; i < myVec.size(); ++i){
        while(myVec[i] != x){                                       //skips forward in vector until where it left off
            ++i;
        }
        while(myVec[i] == x){                                       //skips duplicates in vector for selecting
            ++i;
        }
        x = myVec[i];
    }
}