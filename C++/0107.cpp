#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 40;

int main() {

    int weight[SIZE][SIZE];

    ifstream file;
    file.open("src/0107.txt");
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < SIZE; j++ )
            file >> weight[i][j];
    file.close();

    int before= 0;
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < i; j++ )
            before += weight[i][j];

    int max = 0;
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < i; j++ )
            if ( max < weight[i][j] )
                max = weight[i][j];

    while ( max > 0 ) {

        for ( int i = 0; i < SIZE; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                if ( weight[i][j] == max ) {

                    weight[i][j] = weight[j][i] = 0;

                    bool connected[SIZE];
                    for ( int k = 0; k < SIZE; k++ )
                        connected[k] = false;
                    connected[i] = true;

                    bool changed;
                    do {

                        changed = false;

                        for ( int k = 0; k < SIZE; k++ ) {
                            if ( connected[k] ) {
                                for ( int l = 0; l < SIZE; l++ ) {
                                    if ( weight[k][l] > 0 and not connected[l] ) {
                                        changed = true;
                                        connected[l] = true;
                                    }
                                }
                            }
                        }
                    } while ( changed );

                    if ( not connected[j] )
                        weight[i][j] = weight[j][i] = max;
                }
            }
        }

        max--;
    }

    int after = 0;
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < i; j++ )
            after += weight[i][j];

    cout << before - after << endl;

    return 0;
}
