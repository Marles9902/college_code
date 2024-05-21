#include <iostream>

using namespace std;

// void changeNum(int&);       // & (ampersand): pass an argument by reference to a function
// // void changeNum(int);         // pass by value 
// void changeText(const string&);         // read only idiom (cant change the string)

// void changeNum(int& x){
//     cout << "INSIDE FUNC " << x << endl;
//     x = 10;
//     cout << "INSIDE FUNC " << x << endl;
// }

int increaseNum(int x){
    int y = x;
    y++;
    return y;
}

void increaseNum(){
    static int y = 0;       // static keeps values from functions in memory until program is done
    cout << y << endl;
    y++;
}

int main (){
    
    int num = 0;
    // cout << "BEFORE: " << num << endl;
    for(int i = 0; i < 10; i++){
        increaseNum();
    }
    // cout << "AFTER: " << num << endl;
    return 0;
}