#include "Tree.h"

// int Tree::objectCount = 0;

// Tree::Tree(){
//     objectCount++;
//     height = 0;
// }

void Tree::water()
{
    height++;
}

ostream& operator<<(ostream& os, const Tree& myTree){
    os << "Tree height: " << myTree.height << endl;
    return os;
}

// Tree& operator<<(Tree& tree1, const Tree& tree2){
//     tree1.height = tree2.height;
//     return tree1;
// }

Tree Tree::operator<<(const Tree& otherTree)        // Tree:: is the scope, these are the operator overloading functions
{
    height = otherTree.height;
    return *this;
}

bool Tree::operator>(const Tree& tree){
    return this->height > tree.height;
}

Tree Tree::operator+(const Tree& tree){
    height = height + tree.height;
    return *this;
}

Tree Tree::operator+(int in){
    height = height + in;
    return *this;
}

Tree operator+(int in, const Tree& tree){
    return Tree{in + tree.height};
}