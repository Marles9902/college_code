#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void mySwap(int&, int&);
int myMin(const vector<int>&, int start_idx, int end_idx);
void bubbleSort(vector<int>& myVec);
void selectionSort(vector<int>& myVec);
void printVector(const vector<int>& myVec);

void mySwap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int myMin(const vector<int>& myVec, int start_idx, int end_idx){
    int min_index = start_idx;
    for(int i = start_idx; i < end_idx; ++i){
        if(myVec[i] < myVec[min_index]){
            min_index = i;
        }
    }
    return min_index;
}

void bubbleSort(vector<int>& myVec){
    for(int i = 0; i < myVec.size(); ++i){
        for(int j = 0; j < myVec.size(); ++j){
            if(myVec[i] < myVec[j]){
                mySwap(myVec[i], myVec[j]);
            }
        }
    }
}

void selectionSort(vector<int>& myVec){
    for(int i = 0; i < myVec.size(); ++i){
        int min_index = myMin(myVec, i, myVec.size());
        mySwap(myVec[min_index], myVec[i]);
    }
}

void printVector(const vector<int>& myVec){
    for(int val : myVec){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> myVec;
    srand(time(0));
    for(int i = 0; i < 10; ++i){
        myVec.push_back(rand() % 10);
    }
    cout << "unsorted: ";
    printVector(myVec);
    cout << "bubble: ";
    bubbleSort(myVec);
    printVector(myVec);
    cout << "selection: ";
    selectionSort(myVec);
    printVector(myVec);
    return 0;
}