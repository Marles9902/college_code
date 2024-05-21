#include <iostream>

using namespace std;

void grabMemory(){
    const int SIZE = 100;
    int* iptr = new int[SIZE];
}

int* createArray(){
    const int SIZE = 100;
    int* iptr = new int[SIZE];
    return iptr;
}

int main(){
    // int* ptrInt = createArray();
    cout << createArray() << endl;

    int arr[10] = {1, 2, 3, 4, 5};
    int arr[10] = {1, 2, 4, 5, 6};

    int size = 20; 
    int* ptrArr = nullptr;
    ptrArr = new int[size]{1, 2, 3};
    // for(int i = 0; i <2*size; ++i){
    //     cout << ptrArr[i] << endl;
    // }

    delete [] ptrArr;               // how to delete dynamic array 
    ptrArr = new int[2 * size]{1, 2, 30};
    for(int i = 0; i <2*size; ++i){
        cout << ptrArr[i] << endl;
    }

    return 0;
}