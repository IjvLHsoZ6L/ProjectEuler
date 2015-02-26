// 0029.cpp
#include <iostream>
using namespace std;

int power(int a, int n) {
    int p = 1;
    for ( int i = 0; i < n; i++ )
        p *= a;
    return p;
}

int main() {

    int target = 100;
    bool unique[target+1][target+1];
    for ( int a = 2; a <= target; a++ )
        for ( int b = 2; b <= target; b++ )
            unique[a][b] = true;

    for ( int a = 2; power(a, 2) <= target; a++ ) {
        for ( int n1 = 2; power(a, n1) <= target; n1++ ) {

            for ( int d = 2; n1 * d <= target; d++ )
                unique[power(a, n1)][d] = false;

            for ( int n2 = 2; n2 < n1; n2++ )
                for ( int d = 1; n1 * d <= target; d++ )
                    unique[power(a, n1)][n2 * d] = false;
        }
    }


    int cnt = 0;
    for ( int a = 2; a <= target; a++ )
        for ( int b = 2; b <= target; b++ )
            if ( unique[a][b] )
                cnt++;

    cout << cnt << endl;

    return 0;
}
