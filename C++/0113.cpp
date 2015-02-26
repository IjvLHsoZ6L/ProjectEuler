// 0113.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 100;

    long long increasing[size + 1][10];

    for ( int d = 1; d <= 9; d++ )
        increasing[1][d] = 1;

    for ( int i = 2; i <= size; i++ ) {

        increasing[i][1] = 1;
        for ( int d = 2; d <= 9; d++ )
            increasing[i][d] = increasing[i - 1][d] + increasing[i][d - 1];
    }

    long long decreasing[size + 1][10];

    decreasing[1][0] = 0;
    for ( int d = 1; d <= 9; d++ )
        decreasing[1][d] = 1;

    for ( int i = 2; i <= size; i++ ) {

        decreasing[i][9] = 1;
        for ( int d = 8; d >= 0; d-- )
            decreasing[i][d] = decreasing[i - 1][d] + decreasing[i][d + 1];
    }

    long long sum = 0;
    for ( int i = 1; i <= size; i++ )
        for ( int d = 1; d <= 9; d++ )
            sum += increasing[i][d];

    for ( int i = 1; i <= size; i++ )
        for ( int d = 0; d <= 9; d++ )
            sum += decreasing[i][d];

    sum -= size * 9;

    cout << sum << endl;

    return 0;
}
