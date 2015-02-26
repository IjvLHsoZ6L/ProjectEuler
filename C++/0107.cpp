// 0107.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 40;

    int weight[size][size];
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < size; j++ )
            cin >> weight[i][j];

    int before= 0;
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < i; j++ )
            before += weight[i][j];

    int max = 0;
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < i; j++ )
            if ( max < weight[i][j] )
                max = weight[i][j];

    while ( max > 0 ) {

        for ( int i = 0; i < size; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                if ( weight[i][j] == max ) {

                    weight[i][j] = weight[j][i] = 0;

                    bool connected[size];
                    for ( int k = 0; k < size; k++ )
                        connected[k] = false;
                    connected[i] = true;

                    bool changed;
                    do {

                        changed = false;

                        for ( int k = 0; k < size; k++ ) {
                            if ( connected[k] ) {
                                for ( int l = 0; l < size; l++ ) {
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
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j < i; j++ )
            after += weight[i][j];

    cout << before - after << endl;

    return 0;
}
