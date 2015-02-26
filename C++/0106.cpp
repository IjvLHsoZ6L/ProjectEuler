// 0106.cpp
#include <iostream>
using namespace std;

int main() {

    int n = 12;

    int less[n/2 + 1][n + 1];
    less[1][1] = 1;

    for ( int m = 1; m < n/2; m++ ) {

        int sum = 0;
        for ( int k = m; k < 2*m; k++ ) {
            sum += less[m][k];
            less[m + 1][k + 1] = sum;
        }
        less[m + 1][2*m + 1] = sum;
    }

    int half[n/2 + 1];
    for ( int m = 1; m <= n/2; m++ ) {

        half[m] = 1;
        for ( int k = m + 1; k <= 2*m; k++ )
            half[m] *= k;
        for ( int k = 1; k <= m; k++ )
            half[m] /= k;

        half[m] /= 2;

        for ( int k = m; k < 2*m; k++ )
            half[m] -= less[m][k];
    }

    int sum = 0;
    for ( int m = 1; m <= n/2; m++ ) {

        int combination = 1;
        for ( int k = 0; k < 2*m; k++ )
            combination *= n - k;
        for ( int k = 1; k <= 2*m; k++ )
            combination /= k;

        sum += combination * half[m];
    }

    cout << sum << endl;

    return 0;
}
