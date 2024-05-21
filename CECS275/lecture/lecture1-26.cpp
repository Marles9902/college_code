/*
 *
 *
 *
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    // //Prompt the user to enter a month
    // unsigned short month; 
    // cout << "PLEASE INPUT YOUR MONTH: ";
    // cin >> month;

    // //This loops accumulates 0.1 ten times
    // double y = 0;
    // float z = 9.8;
    // for(int i = 0; i < 10; ++i){
    //     y += 0.1;
    // }

    // //Display the difference between y and 1
    // cout << (y - 1) << endl;

    // //Testing the closeness of y and 1
    // if(abs(y - 1) < 10E-16){
    //     cout << "NOW THE SAME" << endl;
    // }
    // cout << "YOUR MONTH: " << month << endl;
    string first_name;
    string last_name;
    // int age;
    // cout << "ENTER YOUR AGE: ";
    // cin >> age;
    cout << "ENTER YOUR LAST NAME: ";
    cin >> last_name;
    cout << "ENTER YOUR FIRST NAME: ";
    cin >> first_name;
    char ch = '\n';
    string name =  last_name + '\n' + first_name;
    // name[0] = 'm';
    cout << name.length() << endl;
    cout << name.substr(1, 4) << endl;
    //cin >> name;
    //cin.ignore();
    //getline(cin, name);
    cout << "MY NAME IS: " << name << endl;
    // cout << "AGE: " << age << endl;

    // //Lab assignment
    // int n;
    // cout << "ENTER a number between 0-1000000: ";
    // cin >> n;
    // cout << n << endl;
    // while(n < 13){
    //     cout << ", " << n + 1;
    // }

    return 0;
}