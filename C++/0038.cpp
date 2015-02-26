// 0038.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e4;

    int max = 0;
    for ( int m = 1; m < target; m++ ) {

        int cat = 0;
        int d = 0;
        for ( int n = 1; d < 9; n++ ) {

            int unit = 1;
            while ( not (m * n < unit) ) {
                unit *= 10;
                d++;
            }

            cat *= unit;
            cat += m * n;
        }

        if ( d == 9 ) {

            int appear[10];
            for ( int k = 0; k < 10; k++ )
                appear[k] = 0;

            int N = cat;
            while ( N > 0 ) {
                appear[N % 10]++;
                N /= 10;
            }

            bool pandigital = (appear[0] == 0);
            for ( int k = 1; k < 10; k++ )
                pandigital and_eq (appear[k] == 1);

            if ( pandigital )
                max = cat;
        }
    }

    cout << max << endl;

    return 0;
}
