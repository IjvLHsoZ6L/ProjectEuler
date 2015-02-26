// 059.cpp
#include <iostream>
using namespace std;

int XOR(int a, int b) {
    int A = a, B = b;

    int c;
    for ( int i = 0; i < 8; i++ ) {
        c *= 2;
        c += (A%2 + B%2)%2;
        A /= 2;
        B /= 2;
    }

    int d = 0;
    for ( int i = 0; i < 8; i++ ) {
        d *= 2;
        d += c%2;
        c /= 2;
    }

    return d;
}

int main() {

    int length = 1201;
    int cipher[length];
    for ( int i = 0; i < length; i++ ) {
        cin >> cipher[i];
    }

    int k[3], kmax[3];
    int max = 0;
    for ( k[0] = 'a'; k[0] <= 'z'; k[0]++ ) {
        for ( k[1] = 'a'; k[1] <= 'z'; k[1]++ ) {
            for ( k[2] = 'a'; k[2] <= 'z'; k[2]++ ) {
                int decry[length];
                for ( int i = 0; i < length; i++ )
                    decry[i] = XOR(cipher[i], k[i%3]);

                int cnt = 0;
                for ( int i = 0; i+2 < length; i++ )
                    if ( decry[i] == 't' or decry[i] == 'T' )
                        if ( decry[i+1] == 'h' )
                            if ( decry[i+2] == 'e' )
                                cnt++;

                if ( max < cnt ) {
                    max = cnt;
                    for ( int i = 0; i < 3; i++ )
                        kmax[i] = k[i];
                }
            }
        }
    }

    int sum = 0;
    for ( int i = 0; i < length; i++ )
        sum += XOR(cipher[i], kmax[i%3]);

    cout << sum << endl;

    return 0;
}
