#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree oak;
    Tree pine;
    // Tree ginko;
    // Tree cherryBlossom;

    // cout << "We have " << oak.getObjectCount() << " tree(s)." << endl;

    // Tree::decorate();

    oak.water();
    pine.water();
    pine.water();

    // operator overloading tests
    cout << oak << pine << endl;            // cout is not part of the class but oak and pine are 
    // (cout << oak) << pine << endl;       // parenthesis returns cout to display pine height as well
    // cout << (oak << pine) << endl;       // this uses the |friend Tree& operator| function

    cout << (oak > pine) << endl;
    cout << (pine + oak) << endl;
    cout << (pine + (8 + oak)) << endl;

    return 0;
}