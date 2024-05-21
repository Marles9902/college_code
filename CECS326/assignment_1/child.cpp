// Marwin Gonzales 027340883
// CECS 326 assignment 1 child.cpp
// terminal input: ./child child_number name_of_child
// description: takes input of child name and number and outputs a sentece

#include <iostream>
using namespace std;

// int argc: counter that stores number of command-line arguments
// char *argv[]: array of pointers to arrays of character objects
int main(int argc, char *argv[])
{
    // output using command-line argument inputs
    cout << "I am child number " << argv[1] << ", and my name is " << argv[2] << "." << endl;   // argv[0] would be ./child

    return 0;
};
