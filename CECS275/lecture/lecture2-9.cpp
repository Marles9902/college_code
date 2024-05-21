#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void printArray(const int arr[], int size){   // if just printing, remember to put const before parameter
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
}

void fillArray(int arr[], int& size, int capacity, int numOfElements){   // int arr[] is pass by reference since we are trying to change it
    srand(time(NULL));
    for(int i = 0; i < numOfElements; ++i){
        if(size < capacity){
            arr[i] = rand() % 6 + 1;
            ++size;
        }
    }
}

void fillArray(ifstream& inFile, int arr[], int& size, int capacity){
    inFile.open("data.txt");
    int num;
    while((size < capacity) && inFile >> num){
        arr[size] = num; 
        ++size;
    }
}

int main(){

    const int CAPACITY = 20; 
    int num[CAPACITY];      // is created on stack (static)
    int size = 0;
    int numOfElements = 10;
    ifstream inFile;
    fillArray(inFile, num, size, CAPACITY);
    cout << "ARRAY SIZE: " << size << endl;
    cout << "ARRAY CAPACITY: " << CAPACITY << endl;
    printArray(num, size);
    return 0; 
}