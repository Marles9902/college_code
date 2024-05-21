#ifndef TREE_H
#define TREE_H

#include <iostream>         // dont use these in a normal header file, these are only for demonstration
using namespace std;        // this too 

class Tree{
    public: 
        Tree(){
            height = 0;
    //     objectCount++;
    // }
    // static void decorate(){
    //     std::cout << objectCount << std::endl;
    // }
    // int getObjectCount() const{
    //     return objectCount;

    // }
    // friend void water(const Tree&){         // friend functions cannot change values but let you not have to use getter fo all data sets
        // std::cout << "Give water" << std::endl;
        }
        Tree(int h){
            height = h;
        }

        void water();
        friend ostream& operator<<(ostream& os, const Tree& myTree);        // friend functions have access to data in private but cannot change them
        // friend Tree& operator<<(Tree& tree1, const Tree& tree2);
        Tree operator <<(const Tree& tree);
        bool operator>(const Tree& tree);
        Tree operator+(const Tree& tree);
        Tree operator+(int in);
        friend Tree operator+(int in, const Tree& tree);

    // ~Tree(){
    //     std::cout << "A tree is cut down." << std::endl;
    // }

    private:
        // static int objectCount;     // this survives until program ends
        int height;
};

#endif