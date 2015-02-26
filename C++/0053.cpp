// 053.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 100 + 1;
    int limit = 1e6;
    int comb[size][size];
    for ( int n = 0; n < size; n++ )
        comb[n][0] = comb[n][n] = 1;

    for ( int n = 1; n < size; n++ ) {
        for ( int r = 1; r < n; r++ ) {
            comb[n][r] = comb[n-1][r-1] + comb[n-1][r];
            if ( comb[n][r] > limit )
                comb[n][r] = limit + 1;
        }
    }

    int cnt = 0;
    for ( int n = 0; n < size; n++ )
        for ( int r = 0; r <= n; r++ )
            if ( comb[n][r] > limit )
                cnt++;

    cout << cnt << endl;

    return 0;
}
