/*
 * This is the header file for the CashRegister class which deals with the prices 
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <iostream>
#include <vector>

//Goal: Scans items by barcode from inventory and adds prices from there
//Currently: Add and pop charges by manual prices
class CashRegister{
    public:
        CashRegister();
        //~CashRegister();
        double getPriceTotal();
        char getPaymentMethod();
        bool getPaymentComplete();
        void setPaymentMethod(char aMethod);
        void setPaymentComplete(bool aT);
        void addPrice(double aPrice);
        void popPrice(char aPop);
        void printTotalPrice();
        void printVec();
    protected:
        std::vector<double> priceVec;
        double priceTotal;
        char paymentMethod;
        bool paymentComplete;
};

#endif