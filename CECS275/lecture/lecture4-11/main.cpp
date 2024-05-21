#include <iostream>

using namespace std;

// recursion 

// 1,1,2,3,5,8,13,...
int fib(int n){
    if(n == 0) return 1;
    else if(n == 1) return 1;
    else return fib(n-1) + fib(n-2);
}

// non-recursive way
unsigned long long fibonacci(int n){
    unsigned long long prev1 = 1, prev2 = 1, curr = 2;
    int count = 1;
    while(count < n){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
        // cout << curr << endl;
        count++;
    }
    return curr;
}

// n! = n * n-1 * n-2 * ... * 3 * 2 * 1
int fact(int n){
    if(n == 0) return 1;
    else return n * fact(n-1);
}

// non-recursive way
int factorial(int n){
    int prod = 1;
    for(int i = 1; i <= n; i++){
        prod *= i;
    }
    return prod;
}

int gcd(int a, int b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}


int main(){
    // cout << fib(50) << endl;
    // cout << fibonacci(50) << endl;
    cout << gcd(75, 100) << endl;
    cout << gcd(100, 75) << endl;
    // cout << fact(6) << endl;
    // cout << factorial(6) << endl;
    return 0;
}