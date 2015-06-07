#include <iostream>
#include <fstream>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    int SIZE = 80;

    int a[SIZE][SIZE];

    ifstream file;
    file.open("src/0083.txt");
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < SIZE; j++ )
            file >> a[i][j];
    file.close();

    int sum[SIZE][SIZE];
    sum[0][0] = a[0][0];
    for ( int i = 1; i < SIZE; i++ )
        sum[i][0] = sum[i - 1][0] + a[i][0];
    for ( int j = 1; j < SIZE; j++ )
        sum[0][j] = sum[0][j - 1] + a[0][j];
    for ( int i = 1; i < SIZE; i++ )
        for ( int j = 1; j < SIZE; j++ )
            sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + a[i][j];

    bool change;
    do {
        change = false;
        for ( int i = 0; i < SIZE; i++ ) {
            for ( int j = 0; j < SIZE; j++ ) {

                int minimum = sum[i][j];
                if ( i > 0 )
                    minimum = min(minimum, sum[i-1][j] + a[i][j]);
                if ( j > 0 )
                    minimum = min(minimum, sum[i][j-1] + a[i][j]);
                if ( i+1 < SIZE )
                    minimum = min(minimum, sum[i+1][j] + a[i][j]);
                if ( j+1 < SIZE)
                    minimum = min(minimum, sum[i][j+1] + a[i][j]);

                if ( minimum < sum[i][j] ) {
                    change = true;
                    sum[i][j] = minimum;
                }
            }
        }
    } while ( change );

    cout << sum[SIZE-1][SIZE-1] << endl;


    return 0;
}
