// 0012.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 500;

    int triangle = 1;
    int delta = 2;
    bool detected = false;
    while ( not detected ) {

        int N = triangle;
        int divisors = 1;
        for ( int d = 2; N > 1; d++ ) {

            int cnt = 0;
            while ( N % d == 0 ) {
                cnt++;
                N /= d;
            }

            divisors *= cnt + 1;
        }

        if ( divisors > target ) {
            detected = true;
            cout << triangle << endl;
        }

        triangle += delta;
        delta++;
    }

    return 0;
}
