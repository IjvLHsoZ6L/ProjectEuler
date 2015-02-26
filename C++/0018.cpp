// 0018.cpp
#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    const int size = 15;
    int x[size][size];

    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            cin >> x[i][j];
        }
    }

    for ( int i = size-2; i >= 0; i-- )
        for ( int j = 0; j <= i; j++ )
            x[i][j] += max(x[i+1][j], x[i+1][j+1]);

    cout << x[0][0] << endl;

    return 0;
}
