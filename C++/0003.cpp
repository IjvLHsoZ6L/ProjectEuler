// 0003.cpp
#include <iostream>
using namespace std;

int main() {

    long long N = 600851475143;

    int max = 0;
    for ( int d = 2; N > 1; d++ ) {
        if ( N % d == 0 ) {

            max = d;

            while ( N % d == 0 )
                N /= d;
        }
    }

    cout << max << endl;

    return 0;
}
