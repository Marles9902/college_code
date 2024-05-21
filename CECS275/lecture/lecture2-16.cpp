#include <iostream>
#include <vector>

using namespace std;

int linSearch(const vector<int>& myVec, int key);
int linSearch(const int arr[], int size, int key);

int linSearch(const vector<int>& myVec, int key){
    for(int i = 0; i < myVec.size(); ++i){
        if(myVec[i] == key){
            return i;
        }
    }
    return -1;
}

int binSearch(const vector<int>& myVec){
    int i = 0 
    int j = myVec.size()-1;
    while(){
        binSearchHelper(myVec, i, j, key);
    }
}


void binSearchHelper(const vector<int>& myVec, int& i, int& j, int key){
    int mid = (i + j) / 2;
    cout << i << " " << j << endl;
    cout << "MID " << mid << endl;
    if(myVec[mid] == key){
        return mid;
    }else if(key < myVec[mid]){
        j = mid - 1;
    }else{
        i = mid + 1;
    }
    // mid = (i + j) / 2;
    return mid;

}

void printResult(const vector<int>& myVec, int index){
    for(int i = 0; i < myVec.size(); ++i){
        if(i == index){
            cout << myVec[i] << "<---" << endl;
        }else{
            cout << myVec[i] << endl;
        }
    }
    if(index == -1){
        cout << "NO ELEMENT FOUND" << endl;
    }
}

void printVector(const vector<int>& myVec){
    for(int val : myVec){
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> myVec;
    for(int i = 0; i < 11; ++i){
        myVec.push_back(2*i);
    }
    printVector(myVec);
    int i = 0;
    int j = myVec.size()-1;
    // binSearch(myVec, i, j, 9);
    // binSearch(myVec, i, j, 9);
    // binSearch(myVec, i, j, 9);
    // binSearch(myVec, i, j, 9);
    // binSearch(myVec, i, j, 9);
    printResult(myVec, binSearch(myVec, key));
    return 0;
}
