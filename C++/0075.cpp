// 075.cpp
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

    int MAX = 1500000;
    int way[MAX+1];
    for ( int L = 0; L <= MAX; L++ )
        way[L] = 0;

    // m : odd and n : odd
    for ( int m = 1; 2*m*m <= MAX; m += 2 )
        for ( int n = m + 2; n*(m + n) <= MAX; n += 2 )
            if ( gcd(m, n) == 1 )
                for ( int k = 1; k*n*(m + n) <= MAX; k++ )
                    way[k*n*(m + n)]++;

    // m : odd and n : even
    for ( int m = 1; 4*m*m <= MAX; m += 2 )
        for ( int n = m + 1; 2*n*(m + n) <= MAX; n += 2 )
            if ( gcd(m, n) == 1 )
                for ( int k = 1; 2*k*n*(m + n) <= MAX; k++ )
                    way[2*k*n*(m + n)]++;

    // m : even and n : odd
    for ( int m = 2; 4*m*m <= MAX; m += 2 )
        for ( int n = m + 1; 2*n*(m + n) <= MAX; n += 2 )
            if ( gcd(m, n) == 1 )
                for ( int k = 1; 2*k*n*(m + n) <= MAX; k++ )
                    way[2*k*n*(m + n)]++;

    int cnt = 0;
    for ( int L = 0; L <= MAX; L++ )
        if ( way[L] == 2 )
            cnt++;

    cout << cnt << endl;

    return 0;
}
