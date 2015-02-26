// 0104.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 20;

    int a[size], b[size], A[size], B[size];
    for ( int i = 0; i < size; i++ )
        a[i] = b[i] = A[i] = B[i] = 0;
    a[1] = b[1] = A[size - 1] = B[size - 1] = 1;

    for ( int k = 3; true; k++ ) {

        int c[size], C[size];

        for ( int i = 1; i < size; i++ ) {
            c[i] = a[i] + b[i];
            C[i] = A[i] + B[i];
        }
        C[0] = 0;

        for ( int i = 1; i + 1 < size; i++ ) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        c[size - 1] %= 10;

        for ( int i = size - 1; i > 0; i-- ) {
            C[i - 1] += C[i] / 10;
            C[i] %= 10;
        }

        if ( C[0] > 0 ) {

            A[0] = B[0] = 0;
            for ( int i = size - 1; i > 0; i-- ) {
                A[i] = A[i - 1];
                B[i] = B[i - 1];
                C[i] = C[i - 1];
            }
            C[0] = 0;
        }

        int appear[9 + 1];
        for ( int d = 0; d <= 9; d++ )
            appear[d] = 0;

        for ( int i = 1; i <= 9; i++ )
            appear[c[i]]++;

        bool pandigital = (appear[0] == 0);
        for ( int d = 1; d <= 9; d++ )
            pandigital and_eq (appear[d] == 1);

        if ( pandigital ) {

            for ( int d = 0; d <= 9; d++ )
                appear[d] = 0;

            for ( int i = 1; i <= 9; i++ )
                appear[C[i]]++;

            pandigital = (appear[0] == 0);
            for ( int d = 1; d <= 9; d++ )
                pandigital and_eq (appear[d] == 1);

            if ( pandigital ) {

                cout << k << endl;

                return 0;
            }
        }

        for ( int i = 0; i < size; i++ ) {

            a[i] = b[i];
            b[i] = c[i];

            A[i] = B[i];
            B[i] = C[i];
        }
    }
}
