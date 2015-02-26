// 0033.cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {

    while ( b > 0 ) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

    int numer = 1, denom = 1;
    for ( int a = 1; a <= 9; a++ ) {
        for ( int b = a + 1; b <= 9; b++ ) {
            for ( int c = 1; c <= 9; c++ ) {

                // case ac / cb = a / b
                if ( a * (10*c + b) == b * (10*a + c) ) {
                    numer *= 10*a + c;
                    denom *= 10*c + b;
                }

                // case ca / bc = a / b
                if ( a * (10*b + c) == b * (10*c + a) ) {
                    numer *= 10*c + a;
                    denom *= 10*b + c;
                }
            }
        }
    }

    cout << denom / gcd(numer, denom) << endl;

    return 0;
}
