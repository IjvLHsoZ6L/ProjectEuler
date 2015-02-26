// 0121.cpp
#include <iostream>
using namespace std;

int main() {

    int turn = 15;

    long long cases[turn + 1][turn + 1];

    cases[0][0] = 1;
    for ( int i = 1; i <= turn; i++ ) {

        cases[i][0] = cases[i - 1][0] * i;

        for ( int j = 1; j < i; j++ )
            cases[i][j] = cases[i - 1][j - 1] + cases[i - 1][j] * i;

        cases[i][i] = cases[i - 1][i - 1];
    }

    long long sum = 0;
    for ( int i = turn / 2 + 1; i <= turn; i++ )
        sum += cases[turn][i];

    long long all = 1;
    for ( int i = 1; i <= turn; i++ )
        all *= i + 1;

    int prize = 1;
    while ( (prize + 1) * sum <= all )
        prize++;

    cout << prize << endl;

    return 0;
}
