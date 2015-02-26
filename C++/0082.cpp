// 082.cpp
#include <iostream>
using namespace std;

int main() {

    int SIZE = 80;

    int a[SIZE][SIZE];
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < SIZE; j++ )
            cin >> a[i][j];

    int minsum[SIZE][SIZE];

    for ( int i = 0; i < SIZE; i++ )
        minsum[i][0] = a[i][0];

    for ( int j = 1; j < SIZE; j++ ) {
        for ( int i = 0; i < SIZE; i++ ) {

            int min = minsum[i][j - 1] +  a[i][j];

            int sum = a[i][j];
            for ( int k = i - 1; k >= 0; k-- ) {
                sum += a[k][j];
                if ( minsum[k][j - 1] + sum < min )
                    min = minsum[k][j - 1] + sum;
            }

            sum = a[i][j];
            for ( int k = i + 1; k < SIZE; k++ ) {
                sum += a[k][j];
                if ( minsum[k][j - 1] + sum < min )
                    min = minsum[k][j - 1] + sum;
            }

            minsum[i][j] = min;
        }
    }

    int min = minsum[0][SIZE - 1];
    for ( int i = 1; i < SIZE; i++ )
        if ( minsum[i][SIZE - 1] < min )
            min = minsum[i][SIZE - 1];

    cout << min << endl;

    return 0;
}
