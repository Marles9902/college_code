/*
 * This is the main file for the whole CashRegister Project, connecting all files together
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "CashRegister.h"
#include "Cash.h"
#include "Debit.h"
#include "Barcode.h"
#include "Inventory.h"

using namespace std;

void InventoryInit();
void TransNumInit();
Inventory Scanner(int aID);
Inventory CheckAttributes(int aID);
string printReceipt();

int transNum = 0;
CashRegister c1;
Cash cashc;
Debit debitc;

vector<Inventory> Inv = {};
vector<Inventory> Queued = {};

void InventoryInit(){
    fstream infile;
    string lineInput;

    int myID;
    int myStock;
    double myPrice;
    string myName;

    infile.open("StoreInventory.txt", ios::in);

    if(!infile){
        cout << "File open failure!!!!" << endl;
    }
    
    //getline i and separate the numbers strings into itemName, itemPrice, and itemStock
    for(int i = 0; i < 20; ++i){ //i < size of inventory 
        Inventory item;

        if(!infile.eof()){
            getline(infile, lineInput, ' ');
            myID = stoi(lineInput);
            //cout << myID << " ";

            getline(infile, lineInput, ' ');
            myStock = stoi(lineInput);
            //cout << myStock << " ";

            getline(infile, lineInput, ' ');
            myPrice = stod(lineInput);
            //cout << myPrice << " ";

            getline(infile, lineInput);
            myName = lineInput;
            //cout << myName << endl;
        }

        item.setItemID(myID);             //infile int from line i
        item.setItemPrice(myPrice);       //infile double from line i
        item.setItemStock(myStock);       //infile int from line i
        item.setItemName(myName);         //infile string from line i
        
        //item.printInfo();

        //add items into Inv vector
        Inv.push_back(item);
    }
    infile.close();
}

void TransNumInit(){
    ifstream infile;
    ofstream outfile;
    string lineInput;

    infile.open("RegTransNum.txt", ios::in);

    if(!infile){
        cout << "File open failure!!!!" << endl;
    }

    if(!infile.eof()){
        getline(infile, lineInput);
        transNum = stoi(lineInput);
        //cout << transNum << endl;
    }

    transNum = transNum + 1;

    if(remove("RegTransNum.txt")){
        //cout << "File deletion successful" << endl;
    }
    else{ cout << "File deletion failure" << endl; }

    outfile.open("RegTransNum.txt");
    outfile << transNum << endl;
    //cout << transNum << endl;

    infile.close();
}

//gets object with an ID equal to the passed in value
Inventory Scanner(int aID){
    Inventory nsItem;
    nsItem.equals(CheckAttributes(aID));
    return nsItem;
}

Inventory CheckAttributes(int aID){
    Inventory cScanned;
    for(int i = 0; i < Inv.size(); ++i){
        if(Inv[i].getItemID() == aID){
            cScanned = (Inv[i]);
            //cout << "Successful scan" << endl;
            return cScanned;
        }
        else{
            //cout << "Failed iteration" << endl;
        }
    }
}

string printReceipt(){
    cout << endl;
    cout <<                                 "\n------------------------------------------------";
    cout <<                                 "\n|                    ALDI'S                    |";
    cout <<                                 "\n|                05 / 11 / 2022                |";
    cout <<                                 "\n|                    09:53pm                   |";
    cout <<                                 "\n|                (800) 555-5555                |";
    cout <<                                 "\n|               Carson, CA 90111               |";
    cout <<                                 "\n|             Transaction number:" << transNum << "            |" <<  endl;

    cout <<                                 "\n                   Item List                    \n";

    for(int i = 0; i < Queued.size(); ++i){
        Queued[i].printInfo2();
        cout << endl;
    }

    cout <<                                 "|               Subtotal: $" << c1.getPriceTotal() << "                |";
    cout <<                                 "\n|               Tax: 12% / $" << (c1.getPriceTotal() * 0.12) << "              |";  
    cout <<                                 "\n|               Total: $" << setprecision(4) << (c1.getPriceTotal() * 1.12) << "                  |";
    if(c1.getPaymentMethod() == 'c'){
        cout <<                             "\n|               Change: $" << setprecision(4) << cashc.getCashOut() << "                 |";
        cout <<                             "\n|               Card Type: N/A                 |";
        cout <<                             "\n|               Account number: N/A            |";
    }
    if(c1.getPaymentMethod() == 'd'){
        cout <<                             "\n|               Change: $0.00                  |";
        cout <<                             "\n|               Card Type: " << debitc.getCardType() << "                  |";
        cout <<                             "\n|               Account number: " << debitc.getCardNum() << " |";
    }
    cout <<                                 "\n|               # of items: " << Queued.size() << "                  |\n";
    cout << endl;
    Barcode b1;
    b1.setBarcode(transNum);
    b1.printBarcode();
    cout << "\n_________________________________________________" << endl;
}

int main(){
    bool finished = 0;

    do{
        InventoryInit();
        TransNumInit();

        char pM;
        double r2, r3, r9, r10;
        char r1, r4;
        string r5, r6, r7;
        int r8;
        bool myLoop = false;

        cout << "Welcome to Aldi's.";

        //scanning loop //done
        while(!myLoop){
            cout << "\nPlease choose your next activity (S to scan an item / Z to remove most recent item / F to finish): ";
            cin >> r4;
            if(r4 == 'F'){
                cout << "\nFinish detected. Proceeding to payment method." << endl;
                cout << "Taxed total: $" << setprecision(4) << (c1.getPriceTotal() * 1.12) << endl;
                myLoop = true; 
            }
            if(r4 == 'Z'){
                cout << "\nMost recent item has been unscanned." << endl;
                Queued.pop_back();
                c1.popPrice('p');
                cout << "Current cost balance: $" << setprecision(4) << c1.getPriceTotal() << endl;
            }
            if(r4 == 'S'){
                cout << "\nPlease enter your item's ID: ";
                cin >> r8;
                Inventory sItem = Scanner(r8);
                Queued.push_back(sItem);
                c1.addPrice(Queued[Queued.size() - 1].getItemPrice());
                cout << "\nScanned item: ";
                Queued[Queued.size() - 1].printInfo1();
                cout << "Current cost balance: $" << setprecision(4) << c1.getPriceTotal() << endl;
            }
        }

        //payment type
        cout << "\nPlease select your payment type (c cash / d debit): ";
        cin >> pM;
        c1.setPaymentMethod(pM);

        if(pM == 'c'){
            cashc.setTotalCharge(c1.getPriceTotal() * 1.12);
            c1.setPaymentMethod('c');

            while(!(cashc.getPaymentComplete())){
                cout << "\nCash has been selected. Please choose your next activity (A to add cash / R to remove cash / F to finish): ";
                cin >> r1;
                if(r1 == 'A'){
                    cout << "\nPlease insert: $";
                    cin >> r9;
                    cashc.addCash(r9);
                    cout << "\nCash entered: $" << setprecision(4) << cashc.getCashIn();
                }
                if(r1 == 'R'){
                    cout << "\nCurrent inputted cash: $" << cashc.getCashIn();
                    cout << "\nPlease remove desired amount: $";
                    cin >> r10;
                    cashc.removeCash(r10);
                    cout << "\nCash entered: $" << setprecision(4) << cashc.getCashIn();
                }
                if(r1 == 'F'){
                    cashc.setPaymentComplete(1);
                    cout << "\nCash entered: $"<< setprecision(4) <<  cashc.getCashIn();
                }
                if(!(cashc.getPaymentComplete())){
                    cout << "\nInsufficient amount has been inserted. Please insert more.";
                }
            }

        }

        if(pM== 'd'){
            debitc.setTotalCharge(c1.getPriceTotal());
            c1.setPaymentMethod('d');

            cout << "\nDebit has been selected. Please insert your card type (Chase / WellsFargo): ";
            cin >> r5;

            if(r5 == "Chase" || r5 == "WellsFargo"){ debitc.setCardType(r5); }
            else{ debitc.setCardType("Invalid"); }

            while(!debitc.getCardAD()){
                cout << "\nPlease insert your card number: ";
                cin >> r7;
                debitc.setCardNum(r7);
                if(r7.length() > 15){
                    cout << "Card has been approved.";
                    debitc.setCardAD(1);
                }

            }
        }
        printReceipt();
        cout << "\nFinished shopping? (Yes = 1 / No = 0): ";
        cin >> finished;
    }while(!finished);

    return 0;
}