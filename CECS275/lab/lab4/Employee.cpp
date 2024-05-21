/*
 * This is the program file for the Employee class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Employee.h"
#include "BankAccount.h"

#include<iostream>

Employee::Employee(std::string empID, std::string n, double s, BankAccount* a){
    id = empID;
    name = n;
    salary = s;
    account = a;
}

void Employee::deposit_monthly_salary(){
    (*account).deposit(salary / 12);
}

void Employee::print() const{
    std::cout << "Employee ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "Monthly Salary: $" << salary / 12 << std::endl;
    std::cout << "Account Balance: $" << (salary / 12) + 2000 << std::endl;
}