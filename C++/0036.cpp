// 0036.cpp
#include <iostream>
using namespace std;

int size = 100;

bool palindromic(int n, int base) {

    int d = -1;
    int digit[size];
    while ( n > 0 ) {
        d++;
        digit[d] = n % base;
        n /= base;
    }

    bool coincide = true;
    for ( int i = 0; 2*i < d; i++ )
        coincide and_eq (digit[i] == digit[d - i]);

    return coincide;
}

int main() {

    int target = 1e6;

    int sum = 0;
    for ( int n = 0; n < target; n++ )
        if ( palindromic(n, 2) and palindromic(n, 10) )
            sum += n;

    cout << sum << endl;

    return 0;
}
