// 0034.cpp
#include <iostream>
using namespace std;

int main() {

    int factorial[10];
    factorial[0] = 1;
    for ( int i = 1; i < 10; i++ )
        factorial[i] = i * factorial[i-1];

    int target = 6*factorial[9];
    int sum = 0;
    for ( int n = 3; n < target; n++ ) {
        int sumoffactorial = 0;
        int N = n;
        while ( N > 0 ) {
            sumoffactorial += factorial[N%10];
            N /= 10;
        }
        if ( sumoffactorial == n )
            sum += n;
    }

    cout << sum << endl;

    return 0;
}
