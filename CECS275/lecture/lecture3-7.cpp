#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    // const char* str1 = "hello";
    // const char* str2 = "hello";
    // char str1[] = "hello";
    // char str2[] = "heLlo";
    // char str[5] = "hiii";
    // char str1[5] = "hi";
    // cout << strcmp(str, str1) << endl;
    // cout << "ENTER A STRING: ";
    // cin >> str;
    // cout << str << endl;
    // cout << strcmp(str1, str2) << endl;
    // cout << int('L') << " " << int('l') << endl;
    char str[80];
    strcpy (str, "these ");
    cout << str << endl;
    strcat (str, "strings ");
    cout << str << endl;
    strcat (str, "are");
    cout << str << endl;
    strcat (str, "concatenated.");
    cout << str << endl;
    cout << strlen(str) << endl;
    
    return 0;
}