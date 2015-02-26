// 0117.cpp
#include <iostream>
using namespace std;

int main() {

    int length = 50;

    long long ways[length + 1];

    ways[0] = 1;
    for ( int l = 1; l <= length; l++ ) {

        ways[l] = ways[l - 1];

        if ( l >= 2 )
            ways[l] += ways[l - 2];

        if ( l >= 3 )
            ways[l] += ways[l - 3];

        if ( l >= 4 )
            ways[l] += ways[l - 4];
    }

    cout << ways[length] << endl;

    return 0;
}
