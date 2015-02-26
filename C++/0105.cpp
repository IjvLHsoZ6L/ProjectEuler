// 0105.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 12 + 2;

    int sum = 0;
    for ( int i = 0; i < 100; i++ ) {

        int a[size], length;
        a[0] = 1; // dummy;

        for ( length = 1; a[length - 1] > 0; length++ )
            cin >> a[length];
        length -= 2;

        for ( int k = length; k > 1; k-- ) {
            for ( int l = 1; l < k; l++ ) {
                if ( a[l] > a[l + 1] ) {
                    int temp = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = temp;
                }
            }
        }

        int b[length + 1];
        b[0] = 0;
        for ( int k = 1; k <= length; k++ )
            b[k] = b[k - 1] + a[k];

        bool propii = true;
        for ( int k = 1; 2 * k < length; k++ )
            propii and_eq (b[k + 1] > b[length] - b[length - k]);

        if ( propii ) {

            bool appear[length + 1][b[length] + 1];
            for ( int k = 0; k <= length; k++ )
                for ( int n = 0; n <= b[k]; n++ )
                    appear[k][n] = false;

            bool propi = true;
            appear[0][0] = true;
            for ( int k = 1; k <= length; k++ ) {
                for ( int n = 0; n <= b[k - 1]; n++ ) {
                    if ( appear[k - 1][n] ) {

                        if ( appear[k][n] )
                            propi = false;

                        appear[k][n] = appear[k][n + a[k]] = true;
                    }
                }
            }

            if ( propi )
                sum += b[length];
        }
    }

    cout << sum << endl;

    return 0;
}
