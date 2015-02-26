// 0052.cpp
#include <iostream>
using namespace std;

int main() {

    bool detect = false;
    for ( int x = 1; not detect; x++ ) {

        int appear[6+1][10];
        for ( int i = 1; i <= 6; i++ )
            for ( int d = 0; d < 10; d++ )
                appear[i][d] = 0;

        for ( int i = 1; i <= 6; i++ ) {
            int N = i*x;
            while ( N > 0 ) {
                appear[i][N%10]++;
                N /= 10;
            }
        }

        bool coincide = true;
        for ( int i = 2; i <= 6; i++ )
            for ( int d = 0; d < 10; d++ )
                coincide and_eq (appear[1][d] == appear[i][d]);

        if ( coincide ) {
            detect = true;
            cout << x << endl;
        }
    }

    return 0;
}
