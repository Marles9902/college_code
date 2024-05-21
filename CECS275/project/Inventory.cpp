/*
 * This is the program file for the Inventory class which handles the inventory file
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Inventory.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern vector<Inventory> Inv;

//constructors
Inventory::Inventory(){
    itemName = "";
    itemPrice = 0.0;
    itemStock = 0;
    itemID = 0;
}

Inventory::Inventory(string aName, double aPrice, int aStock, int aID){
    itemName = aName;
    itemPrice = aPrice;
    itemStock = aStock;
    itemID = aID;
}

//~Inventory(){}

//getters and setters
string Inventory::getItemName(){
    return itemName;
}

double Inventory::getItemPrice(){
    return itemPrice;
}

int Inventory::getItemStock(){
    return itemStock;
}

int Inventory::getItemID(){
    return itemID;
}

void Inventory::setItemName(string aName){
    itemName = aName;
}

void Inventory::setItemPrice(double aPrice){
    itemPrice = aPrice;
}

void Inventory::setItemStock(int aStock){
    itemStock = aStock;
}

void Inventory::setItemID(int aID){
    itemID = aID;
}

//methods
void Inventory::equals(Inventory aItem){
    itemName = aItem.getItemName();
    itemPrice = aItem.getItemPrice();
    itemStock = aItem.getItemStock();
    itemID = aItem.getItemID();
}

void Inventory::printInfo1(){
    cout << itemName << endl;
    cout << "Item price: " << itemPrice << endl;
}
void Inventory::printInfo2(){
    cout << "                 Item name: " << itemName << endl;
    cout << "                 Item price: " << itemPrice << endl;
    cout << "                 Qty: 1" << endl;
}