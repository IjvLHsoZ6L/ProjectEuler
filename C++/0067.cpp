// 067.cpp
#include <iostream>
using namespace std;

int main() {
    const int size = 100;
    int x[size][size];

    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            cin >> x[i][j];
        }
    }

    for ( int i = size-2; i >= 0; i-- )
        for ( int j = 0; j <= i; j++ )
            x[i][j] += ((x[i+1][j] < x[i+1][j+1]) ? x[i+1][j+1] : x[i+1][j]);

    cout << x[0][0] << endl;

    return 0;
}
