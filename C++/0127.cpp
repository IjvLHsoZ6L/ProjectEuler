// 0127.cpp
#include <iostream>
using namespace std;

int gcd(int n, int m) {

    while ( m > 0 ) {
        int r = n % m;
        n = m;
        m = r;
    }

    return n;
}

int main() {

    int target = 120000;

    int radical[target];
    for ( int n = 1; n < target; n++ )
        radical[n] = 1;

    for ( int n = 1; n < target; n++ )
        if ( radical[n] == 1 )
            for ( int m = 1; n * m < target; m++ )
                radical[m * n] *= n;

    long long sum = 0;
    for ( int c = 1; c < target; c++ )
        if ( 2 * radical[c] < c )
            for ( int a = 1; 2 * a < c; a++ )
                if ( (long long) radical[a] * radical[c - a] * radical[c] < c )
                    if ( gcd(a, c - a) == 1 )
                        sum += c;

    cout << sum << endl;

    return 0;
}
