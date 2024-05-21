#include <iostream> 

using namespace std;

void toLowercase(string& myString){
    for(int i = 0; i < myString.size(); ++i){
        if(myString[i] >= 'A' && myString[i] <= 'Z'){\
            myString[i] = static_cast<char>(myString[i] + ('a' - 'A'));
        }
    }
}

void mySwap(int* x, int* y){ // this is pass by value not by reference 
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 10;
    int y = 19;
    mySwap(&x, &y);
    cout << x << " " << y << endl;
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // // cout << arr << endl;
    // for(int i = 0; i < 10; ++i){
    //     cout << &arr[i] << " "  << *(arr + i) << endl;
    // }

    // int* ptrArr = arr;
    // cout << ptrArr << endl;

    // int x = 10;
    // int* ptrX = &x;
    // int** ptr_ptrX = &ptrX;
    // cout << x << endl;
    // cout << ptrX << endl;
    // cout << &ptrX << endl;
    // cout << ptr_ptrX << endl;
    // double y = 10.0;
    // double* ptrY = &y;

    // int x = 10;
    // int* ptrX = &x;
    // cout << x << endl;
    // cout << ptrX << endl;
    // cout << ptrX + 1 << endl;

    // cout << &ptrX << endl;
    // cout << *ptrX + 1 << endl;


    // string myString = "ZEBbbRAaaa";
    // cout << myString << endl;
    // toLowercase(myString);
    // cout << myString << endl;

    return 0;
}