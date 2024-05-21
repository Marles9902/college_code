#include <iostream>
#include <cmath>

using namespace std;
void displayMenu();
int selectOption();
void displayPrice(int option);
double processPayment(int option, double deposit);
bool isValid(int option);
int main(){

    int num;
    char ans;
    do {
        displayMenu();
        int opt = selectOption();
        displayPrice(opt);
        double deposit;
        cout << "PLEASE INSERT YOUR PAYMENT: ";
        cin >> deposit;
        if(isValid(opt)){
            double change = processPayment(opt, deposit);
            cout << "Your change is: " << change << endl;
        }
        cout << "WOULD YOU LIKE TO CONTINUE? (Y/N) ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    cout << "Thank you for purchasing" << endl;

    // // * USE IN LAB TO ASK USER IF THEY WANT TO CONTINUE
    // int num;
    // char ans;
    // do {
    //     cout << "ENTER A NUMBER:";
    //     cin >> num;
    //     cout << "You have entered " << num << endl;
    //     cout << "WOULD YOU LIKE TO CONTINUE? (Y/N) ";
    //     cin >> ans;
    // }while(ans == 'y' || ans == 'Y');
    // cout << "Thank you for using the program" << endl;

    
    return 0;
}

bool isValid(int option){
    return option >= 1 && option <= 4;
}

double processPayment(double deposit){
    return deposit - getPrice(option);
}

void displayMenu(){
    cout << "1. Coke" << endl;
    cout << "2. Sprite" << endl;
    cout << "3. Fanta" << endl;
    cout << "4. Dasani" << endl;
}

int selectOption(){
    int option;
    cout << "ENTER YOUR OPTION: ";
    cin >> option;
    return option;
}

void displayPrice(int option){
    switch(option){
        case 1: 
            cout << "Coke: $1.50" << endl;
            break;
        case 2: 
            cout << "Sprite: $2.50" << endl;
            break;
        case 3: 
            cout << "Fanta: $1.00" << endl;
            break;
        case 4: 
            cout << "Dasani: $3.00" << endl;
            break;
        default:
            cout << "Your option is invalid" << endl;
            break;
    }
}

void getPrice(int option){
    switch(option){
        case 1: 
            cout << "Coke: $1.50" << endl;
            break;
        case 2: 
            cout << "Sprite: $2.50" << endl;
            break;
        case 3: 
            cout << "Fanta: $1.00" << endl;
            break;
        case 4: 
            cout << "Dasani: $3.00" << endl;
            break;
        default:
            cout << "Your option is invalid" << endl;
            break;
    }
}

double getPrice(int option){
    switch(option){
        case 1: 
            return 1.50;
        case 2: 
            return 2.50;
        case 3: 
            return 1.00;
        case 4: 
            return 3.00;
        default:
            return 0.00;
    }
}

double mySqrt(double num){
}