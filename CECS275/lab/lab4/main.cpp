/*
 * This is the tester file for the BankAccount and Employee classes
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "BankAccount.h"
#include "Employee.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Employee> employees;
    for(int i = 0; i < 10; ++i){
        BankAccount* bank = new BankAccount(BankAccount());

        employees.push_back(Employee("0001101221", "Minh Nguyen", 40000, bank));
        delete bank;
    }

    employees[1].print();

    return 0;
}