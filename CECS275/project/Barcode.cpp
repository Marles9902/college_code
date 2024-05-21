/*
 * This is the program file for the Barcode class which prints a barcode on the receipt
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Barcode.h"

using namespace std;

//constructors
Barcode::Barcode(){
    
}

//want to infile a number into this aNum
Barcode::Barcode(int aNum){
    transNum = aNum;
}

//Barcode::~Barcode(){}

//getters and setters
int Barcode::getTransNum(){
    return transNum;
}

string Barcode::getBarcode(){
    return newBarcode;
}

void Barcode::setTransNum(int aNum){
    transNum = aNum;
}

void Barcode::setBarcode(int aNum){
    string set1, set2, set3;

    switch((aNum % 1000) / 100){
        case 0: set1 = "| | | | "; break;
        case 1: set1 = "| | | ||"; break;
        case 2: set1 = "| | ||| "; break;
        case 3: set1 = "| | ||||"; break;
        case 4: set1 = "| ||| | "; break;
        case 5: set1 = "| ||| ||"; break;
        case 6: set1 = "| ||||| "; break;
        case 7: set1 = "| ||||||"; break;
        case 8: set1 = "||| | | "; break;
        case 9: set1 = "||| | ||"; break;
        default: set1 = "        "; break;
    }

    switch((aNum % 100) / 10){
        case 0: set2 = "| | | | "; break;
        case 1: set2 = "| | | ||"; break;
        case 2: set2 = "| | ||| "; break;
        case 3: set2 = "| | ||||"; break;
        case 4: set2 = "| ||| | "; break;
        case 5: set2 = "| ||| ||"; break;
        case 6: set2 = "| ||||| "; break;
        case 7: set2 = "| ||||||"; break;
        case 8: set2 = "||| | | "; break;
        case 9: set2 = "||| | ||"; break;
        default: set2 = "        "; break;
    }

    switch(aNum % 10){
        case 0: set3 = "| | | | "; break;
        case 1: set3 = "| | | ||"; break;
        case 2: set3 = "| | ||| "; break;
        case 3: set3 = "| | ||||"; break;
        case 4: set3 = "| ||| | "; break;
        case 5: set3 = "| ||| ||"; break;
        case 6: set3 = "| ||||| "; break;
        case 7: set3 = "| ||||||"; break;
        case 8: set3 = "||| | | "; break;
        case 9: set3 = "||| | ||"; break;
        default: set3 = "        "; break;
    }
    newBarcode = set1 + set2 + set3;
}

//methods
void Barcode::printBarcode(){
    cout << "|             " <<  newBarcode << "         |";
}