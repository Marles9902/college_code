#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

    // * WHILE LOOPS

    // int counter = 0;
    // string str = "international";
    // while(counter < str.length()){
    //     //if(counter % 2 == 0){
    //         //cout << str.substr(counter, 3) << endl;
    //     //}
    //     cout << str[counter] << endl;
    //     counter++; 
    // }

    // * different ways to increment
    // int x = 0;
    // x = x + 1;
    // x += 1;
    // ++x; // best one for C++
    // cout << x << endl;

    // FIXME
    // int x = 0;
    // string str = "international";
    // while(x++ < str.length()){
    //     cout << str[x] << endl;
    // }

    // * example of an idiom
    // string str1 = "hello";
    // string str2 = "hello";
    // int p = -1, q = -1;
    // bool isDone = false; // flag is prolly better to use than break 
    // while(!isDone && ++p == ++q && p < str1.length() && q < str2.length()){
    //     cout << p << " " << q << endl;
    //     if(str1[p] != str2[q]){
    //         cout << "NOT THE SAME" << endl;
    //         isDone = true;
    //     }
    // }

    // * do-while loop executes first then checks condition
    // string str1 = "hello";
    // string str2 = "hello";
    // int p = 0, q = 0;
    // do{
    //     cout << p << " " << q << endl;
    // }while(++p == ++q && p < str1.length() && q < str2.length());

///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // * READING FILES
    // dir in terminal lists files in directory
    
    ifstream infile;
    ofstream outfile;

    infile.open("data.txt");
    outfile.open("result.txt");
    // * checking whether the file actually exists 
    if(!infile){
        cerr << "File open failure!!!!" << endl;    // cerr is the same as cout but just for errors
        return 89;      // just some random number (these are the numbers that displayed when an error occurs on your pc)
        //exit(19);     // another way 
    }
    // int x;
    // while(true){     // asks user continuously for input
    //     cout << "ENTER A NUMBER: ";
    //     cin >> x;
    //     cout << "YOU HAVE ENTERED: " << x << endl;
    // }

    string word;
    while(infile >> word){
        //bool isANumber = true;
        unsigned int num = 0;
        for(char ch : word){
            if(ch >= '0' && ch <= '9'){
                num = num * 10 + (ch - '0');
            }else{
                //isANumber = false;
                //break;
            }
        }
        outfile << num << "\n";
    }

    outfile.close();
    infile.close();
    return 0;
}

// while(inFile >> num >> str) 