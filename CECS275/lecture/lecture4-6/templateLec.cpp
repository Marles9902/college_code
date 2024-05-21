#include <iostream>

using namespace std;

// template allows the use of multiple data types (in this instance: int, float, double, long, etc)
template<class T>
T square(T number){
    return number * number;
}

template<class T>
T multiply(T number1, T number2){
    return number1 * number2;
}
template<class T>
T multiply(T number1, T number2, T number3){
    return number1 * number2 * number 3;
}

int main (void) {
    int num = 10L;
    cout << square(num) << endl;
    cout << multiply(90, 20.0, 10) << endl;

    return 0;
}