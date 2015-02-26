// 0013.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 100;
    int dmax = 100;
    int dgiven = 50;

    int value[dmax];
    for ( int i = 1; i < dmax; i++ )
        value[i] = 0;

    for ( int i = 0; i < size; i++ ) {

        for ( int j = 0; j < dgiven; j++ ) {
            int n;
            cin >> n;
            value[50 - j] += n;
        }

        for ( int j = 1; j+1 < dmax; j++ ) {
            value[j+1] += value[j] / 10;
            value[j] %= 10;
        }
    }

    int j = dmax-1;
    while ( value[j] == 0 )
        j--;

    for ( int k = 0; k < 10; k++ )
        cout << value[j-k];
    cout << endl;

    return 0;
}
