#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

int main() {

    int value[SIZE][SIZE];

    ifstream file;
    file.open("src/0011.txt");
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < SIZE; j++ )
            file >> value[i][j];
    file.close();

    int max = 0;

    for ( int i = 0; i < SIZE; i++ ) {
        for ( int j = 0; j+4 <= SIZE; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i][j+k];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= SIZE; i++ ) {
        for ( int j = 0; j < SIZE; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i+k][j];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= SIZE; i++ ) {
        for ( int j = 0; j+4 <= SIZE; j++ ) {

            int product = 1;
            for ( int k = 0; k < 4; k++ )
                product *= value[i+k][j+k];

            if ( max < product )
                max = product;
        }
    }

    for ( int i = 0; i+4 <= SIZE; i++ ) {
        for ( int j = 3; j < SIZE; j++ ) {

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
