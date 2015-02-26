// 086.cpp
#include <iostream>
using namespace std;

bool square(int n) {
    int r = 0;
    while ( r*r < n )
        r++;
    return r*r == n;
}

int main() {

    int M = 0;
    int target = 1e6;
    int cnt = 0;

    do {

        M++;

        // x = M
        // w = y + z
        int r = M;
        for ( int w = 2; w <= 2*M; w++ ) {

            while ( r*r < M*M + w*w )
                r++;

            if ( r*r == M*M + w*w ) {
                if ( w-1 < M )
                    cnt += (w-1) - (w+1)/2 + 1;
                else
                    cnt += M - (w+1)/2 + 1;
            }
        }

    } while ( cnt <= target );

    cout << M << endl;

    return 0;
}
