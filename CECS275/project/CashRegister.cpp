/*
 * This is the program file for the CashRegister class which deals with the prices 
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "CashRegister.h"
#include "Inventory.h"
#include <iostream>
#include <vector>

using namespace std;

//constructors
CashRegister::CashRegister(){
    priceVec = {};
    priceTotal = 0.0;
    paymentMethod;
    paymentComplete = 0;
}

//CashRegister::~CashRegister(){}

//getters and setters
double CashRegister::getPriceTotal(){
    return priceTotal;
}

char CashRegister::getPaymentMethod(){
    return paymentMethod;
}

bool CashRegister::getPaymentComplete(){
    return paymentComplete;
}

void CashRegister::setPaymentMethod(char aMethod){
        paymentMethod = aMethod;
}

void CashRegister::setPaymentComplete(bool aT){
    paymentComplete = aT;
}

//methods
void CashRegister::addPrice(double aPrice){
    priceTotal = priceTotal + aPrice;
    priceVec.push_back(aPrice);
}

void CashRegister::popPrice(char aPop){
    if(aPop == 'p'){
        int lastPos = priceVec.size();
        priceTotal = priceTotal - priceVec[lastPos - 1];
        priceVec.pop_back();
    }
}

void CashRegister::printTotalPrice(){
    cout << priceTotal << endl;
}

void CashRegister::printVec(){
    for(double price : priceVec){
        cout << price << " ";
    }
    cout << endl;
}