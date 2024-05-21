#include <iostream>
#include "MyStack.h"

using namespace std;

bool isBalanced(string& str);

bool isBalanced(string& str){
    MyStack<string> mStack;
    int i = 0;
    string temp_str;
    do{
        temp_str = str[i] + "";
        if(temp_str == "(")
            mStack.push(temp_str);
        else
            mStack.pop(temp_str);
        i++;
    }while(!(mStack.isEmpty() || i == str.length()));
    cout << "SIZE " << mStack.size() << endl;
    return mStack.isEmpty();
}

int main()
{
    string mathExpression = "(9 + 9 * ((4 - 5) / 5 + (4 * 7))";
    string parenthesesOnly = "((()())";
    cout << isBalanced(parenthesesOnly) << endl;
    
    // MyStack<int> mStack;
    // mStack.push(10);
    // mStack.push(9);
    // mStack.push(8);
    // mStack.push(2);
    // mStack.display();

    return 0;
}