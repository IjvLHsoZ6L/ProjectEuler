// 0114.cpp
#include <iostream>
using namespace std;

int main() {

    int length = 50;

    long long ways[length + 1];
    for ( int l = 0; l < 3; l++ )
        ways[l] = 1;

    for ( int l = 3; l <= length; l++ ) {

        ways[l] = ways[l - 1];

        for ( int b = 3; l - b - 1 >= 0; b++ )
            ways[l] += ways[l - b - 1];

        ways[l] += ways[l - l];
    }

    cout << ways[length] << endl;

    return 0;
}
