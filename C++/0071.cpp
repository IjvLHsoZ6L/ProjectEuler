// 071.cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int A = a, B = b;
    while ( B > 0 ) {
        int r = A % B;
        A = B;
        B = r;
    }
    return A;
}

int main() {

    int MAX = 1e6;

    int d0 = 1, n0 = 0;
    for ( int d = 1; d < MAX; d++ ) {

        int n = 3*d/7;

        if ( n0*d < n*d0 and 7*n < 3*d ) {
            n0 = n;
            d0 = d;
        }
    }

    cout << n0 / gcd(d0, n0) << endl;

    return 0;
}
