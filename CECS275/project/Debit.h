/*
 * This is the header file for the Debit class which handles payments from card
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef DEBIT_H
#define DEBIT_H

#include "CashRegister.h"
#include <iostream>
#include <string>

using namespace std;

//Goal: Takes card number and records it to file with the charge amount, stores card type
//Currently: Takes and stores card number and stores amount charged
class Debit : public CashRegister{
    public:
        Debit();
        Debit(double aNum);
        //~Debit();
        string getCardNum();
        bool getCardAD();
        string getCardType();
        void setTotalCharge(double aNum);
        void setCardNum(string aNum);
        void setCardAD(bool aAD);
        void setCardType(string aType);
    private:
        string cardNum;
        bool cardAD;
        double totalCharge;
        string cardType;
};

#endif