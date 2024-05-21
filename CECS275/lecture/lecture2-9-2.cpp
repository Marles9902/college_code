#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<int>& myVec){    // vectors are pass by value by default 
    for(int i =0; i < 10; ++i){
        myVec[i] = 2 * i;
    }
}

// // you CAN return a vector 
// vector<int> update(){
//     vector<int> num;
//     return num;
// }

void update(vector<int>& myVec){
    myVec.pop_back();
}

void printVector(const vector<int>& myVec){
    for(int i = 0; i < myVec.size(); ++i){
        cout << myVec[i] << " ";
    }
}

int main(){
    vector<int> vec(100);
    fillVector(vec);
    printVector(vec);
    update(vec);
    printVector(vec);
    return 0;
}