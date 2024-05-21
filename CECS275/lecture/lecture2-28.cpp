#include <iostream> 
#include <time.h>

using namespace std;

int* copyArray(const int arr[], int size){
    int* copy_arr = new int[2 * size];
    for(int i = 0; i < size; ++i){
        copy_arr[i] = arr[i];
    }
    return copy_arr;
}

int* fillArray(int arr[]){
    srand(time(0));
    // int* arr = new int[10];
    // int arr[10];                 // common mistake: not dynamically allocated (called on a stack)
    for(int i = 0; i < 10; ++i){
        arr[i] = rand() % 100;
    }
    return arr;
}

int* fillArray(){
    srand(time(0));
    int* arr = new int[10];
    // int arr[10];                 // common mistake: not dynamically allocated (called on a stack)
    for(int i = 0; i < 10; ++i){
        arr[i] = rand() % 100;
    }
    return arr;
}

void printArray(int* ptr){
    for(int i = 0; i < 20; ++i){
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // int* ptr = fillArray(arr);
    int* cPtr = copyArray(arr, 10);
    printArray(cPtr);
    // int* ptr = fillArray();     // dynamically allocated
    // cout << *ptr << endl;
    // printArray(ptr);
    // delete [] ptr;              // only delete dynamically allocated things 

    return 0;
}