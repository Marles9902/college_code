#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> intList;
    intList.appendNode(9);
    intList.displayList();
    cout<<"Hello World";

    return 0;
}
