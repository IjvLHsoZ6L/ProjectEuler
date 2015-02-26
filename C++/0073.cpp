// 073.cpp
#include <iostream>
using namespace std;

int main() {

    const int MAX = 12000;

    static bool proper[MAX+1][MAX+1];
    for ( int d = 2; d <= MAX; d++ )
        for ( int n = 1; n < d; n++ )
            proper[d][n] = true;

    for ( int d = 2; d <= MAX; d++ )
        for ( int n = 1; n < d; n++ )
            if ( proper[d][n] )
                for ( int k = 2; k*d <= MAX; k++ )
                    proper[k*d][k*n] = false;

    int cnt = 0;
    for ( int d = 2; d <= MAX; d++ ) {
        int n = d/3 + 1;
        while ( 2*n < d ) {
            if ( proper[d][n] )
                cnt++;
            n++;
        }
    }

    cout << cnt << endl;

    return 0;
}
