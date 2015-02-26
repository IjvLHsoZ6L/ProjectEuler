// 0011.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 20;

    int value[size][size];
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < size; j++ )
            cin >> value[i][j];

    int max = 0;

    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j+4 <= size; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i][j+k];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= size; i++ ) {
        for ( int j = 0; j < size; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i+k][j];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= size; i++ ) {
        for ( int j = 0; j+4 <= size; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i+k][j+k];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= size; i++ ) {
        for ( int j = 3; j < size; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i+k][j-k];

            if ( max < product )
                max = product;
        }
    }

    cout << max << endl;

    return 0;
}
