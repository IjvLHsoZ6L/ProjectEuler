// 080.cpp
#include <iostream>
using namespace std;

int main() {

    int sum = 0;

    int r = 0;
    for ( int n = 1; n <= 100; n++ ) {

        while ( (r+1)*(r+1) <= n )
            r++;

        if ( r*r < n ) {

            int root[100];
            root[0] = r;
            for ( int i = 1; i < 100; i++ )
                root[i] = 0;

            int square[199];
            square[0] = r*r;
            for ( int i = 1; i < 199; i++ )
                square[i] = 0;

            sum += r;

            for ( int k = 1; k < 100; k++ ) {
                bool safe = true;
                while ( safe ) {
                    int s[2*k + 1];
                    for ( int i = 0; i <= 2*k; i++ )
                        s[i] = square[i];
                    for ( int i = 0; i <= k; i++ )
                        s[k + i] += 2*root[i];
                    s[2*k] += 1;
                    for ( int i = 2*k; i > 0; i-- ) {
                        s[i - 1] += s[i] / 10;
                        s[i] %= 10;
                    }

                    if ( s[0] < n ) {
                        root[k]++;
                        for ( int i = 0; i <= 2*k; i++ )
                            square[i] = s[i];
                    }
                    else
                        safe = false;
                }
                sum += root[k];
            }
        }
    }

    cout << sum << endl;

    return 0;
}
