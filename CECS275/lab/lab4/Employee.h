/*
 * This is the header file for the Employee class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "BankAccount.h"
#include <string>

class Employee{
    public:
        /*
         * Constructs an employee with an id, given name, salary, and bank account.
         * @param empID the id
         * @param n the name
         * @param s the annual salary
         * @param a a pointer to the bank account
         */
        Employee(std::string empID, std::string n, double s, BankAccount* a);
        /*
         * Deposits one month's salary into the bank account.
         */
        void deposit_monthly_salary();
        /*
         * Prints this employee's information to cout
         */
        void print() const;
    private:
        std::string id;
        std::string name;
        double salary;
        BankAccount* account;
};

#endif