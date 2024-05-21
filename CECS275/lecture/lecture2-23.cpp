#include <iostream> 

using namespace std;

int main()
{
    int* ptr = new int(10);         // assign value with the address (pointer is in STACK, value is in HEAP)
    cout << ptr << endl;        // address of value     (in heap)
    cout << *ptr << endl;       // content of pointer
    cout << &ptr << endl;       // address of pointer   (in stack)
    delete ptr;
    ptr = nullptr;

    cout << *ptr << endl;

    // ptr = new int(100);
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << &ptr << endl;
    // int x = new int;        // error

    // // int* ptr = &f;           // both content and address CAN be changed

    // // pointer to a constant
    // const int x = 10;
    // const int* ptrX = &x;       // content CANNOT be changed
    // // *ptrX = 10;          // error
    // cout << x << endl;

    // // constant pointer 
    // int y = 9;
    // int* const ptrY = &y;       // address CANNOT be changed
    // // ptrY = &x;           // error 
    // *ptrY = 10;
    // cout << y << endl;

    // int z = 10;
    // const int* const ptrZ = &z; // both content and address CANNOT be changed
    

    return 0;
}