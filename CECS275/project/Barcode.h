/*
 * This is the header file for the Barcode class which prints a barcode on the receipt
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef BARCODE_H
#define BARCODE_H   

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Goal: get prompt from user input, read file for what transaction number is currently there,
//      create barcode with ascii values (each bar is a num), and increment the file when done
//Currently: 
class Barcode{
    public:
        Barcode();
        Barcode(int aNum);
        //~Barcode();
        int getTransNum();
        string getBarcode();
        void setTransNum(int aNum);
        void setBarcode(int aNum);
        void printBarcode();
    protected:
        int transNum;
        string newBarcode;
};

#endif