/*
 * This is the program file for the BankAccount class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "BankAccount.h"

BankAccount::BankAccount(){
    this->balance = 2000.00;
}

void BankAccount::deposit(double amount){
    this->balance += amount;
}

void BankAccount::withdraw(double amount){
    this->balance -= amount;
}

double BankAccount::get_balance() const{
    return this->balance;
}

std::string BankAccount::get_id() const{
    return this->id;
}

void BankAccount::set_id(std::string id){
    this->id = id;
}