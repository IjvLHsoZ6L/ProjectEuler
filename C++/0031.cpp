// 0031.cpp
#include <iostream>
using namespace std;

int main() {

    int coins = 8;
    int value[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int target = 200;

    int ways[coins][target + 1];
    for ( int n = 0; n <= target; n++ )
        ways[0][n] = 1;

    for ( int i = 1; i < coins; i++ ) {

        for ( int n = 0; n < value[i]; n++ )
            ways[i][n] = ways[i - 1][n];
        for ( int n = value[i]; n <= target; n++ )
            ways[i][n] = ways[i - 1][n] + ways[i][n - value[i]];
    }

    cout << ways[coins-1][target] << endl;

    return 0;
}
