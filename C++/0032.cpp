// 0032.cpp
#include <iostream>
using namespace std;

int main() {

    bool product[9999 + 1];
    for ( int n = 0; n <= 9999; n++ )
        product[n] = false;

    // case X * YYYY = ZZZZ
    for ( int x = 0; x <= 9; x++ ) {
        for ( int y = 0; y <= 9999; y++ ) {

            int appear[10];
            for ( int d = 0; d <= 9; d++ )
                appear[d] = 0;

            int X = x;
            while ( X > 0 ) {
                appear[X % 10]++;
                X /= 10;
            }

            int Y = y;
            while ( Y > 0 ) {
                appear[Y % 10]++;
                Y /= 10;
            }

            int Z = x * y;
            while ( Z > 0 ) {
                appear[Z % 10]++;
                Z /= 10;
            }

            bool pandigital = (appear[0] == 0);
            for ( int j = 1; j <= 9; j++ )
                pandigital and_eq (appear[j] == 1);

            if ( pandigital )
                product[x * y] = true;
        }
    }

    // case XX * YYY = ZZZZ
    for ( int x = 0; x <= 99; x++ ) {
        for ( int y = 0; y <= 999; y++ ) {

            int appear[10];
            for ( int d = 0; d <= 9; d++ )
                appear[d] = 0;

            int X = x;
            while ( X > 0 ) {
                appear[X % 10]++;
                X /= 10;
            }

            int Y = y;
            while ( Y > 0 ) {
                appear[Y % 10]++;
                Y /= 10;
            }

            int Z = x * y;
            while ( Z > 0 ) {
                appear[Z % 10]++;
                Z /= 10;
            }

            bool pandigital = (appear[0] == 0);
            for ( int j = 1; j <= 9; j++ )
                pandigital and_eq (appear[j] == 1);

            if ( pandigital )
                product[x * y] = true;
        }
    }

    int sum = 0;
    for ( int n = 0; n <= 9999; n++ )
        if ( product[n] )
            sum += n;

    cout << sum << endl;

    return 0;
}
