// 076.cpp
#include <iostream>
using namespace std;

int main() {

    int way[101][101];

    for ( int i = 0; i <= 100; i++ )
        way[0][i] = 1;

    for ( int n = 1; n <= 100; n++ ) {
        way[n][0] = 0;
        for ( int i = 1; i <= n; i++ )
            way[n][i] = way[n - i][i] + way[n][i - 1];
        for ( int i = n + 1; i <= 100; i++ )
            way[n][i] = way[n][n];
    }

    cout << way[100][99] << endl;

    return 0;
}
