#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int bookmark = 0;
int counter = 0;
int myMax = 10;

void bubbleSort(vector<int>& myVec);
void mySortSwap(int&, int&);
void printVector(vector<int> myVec);

void output(ofstream& outfile, vector<int> myVec);
void mySelector(vector<int> myVec);

void bubbleSort(vector<int>& myVec){
    for(int i = 0; i < myVec.size(); ++i){
        for(int j = 0; j < myVec.size(); ++j){
            if(myVec[i] < myVec[j]){
                mySortSwap(myVec[i], myVec[j]);
            }
        }
    }
}

void mySortSwap(int& t, int& y){
    int z = t;
    t = y;
    y = z;
}

void printVector(vector<int> myVec){
    for(int i = 0; i < myVec.size(); ++i){
        cout << myVec[i] << ", ";
    }
}

//++x somewhere
void mySelector(vector<int> myVec){
    int counter = 0;
    // cout << bookmark << endl;
    // cout << myVec[myVec.size() - 1] << endl;
    for(int i = 0; i < myVec[(myVec.size()-1) - myVec[0]]; ++i){
        cout << i + 14 << endl;
        int count = 0;
        int bookmark = myVec[i];
        // cout << bookmark << endl;
        if(bookmark == myVec[i]){
            count = counter + 1;
        }
        cout << bookmark << " " << count << endl;
    }

}

int main(){
    vector<int> myVec = {38, 14, 29, 14, 28};

    bubbleSort(myVec);
    for(int i = 0; i < myVec.size(); ++i){
        cout << myVec[i] << " ";
    }

    cout << endl;

    // for(int j = 0; j < myVec[myVec.size() - 1]; ++j){
        mySelector(myVec);
    // }

}