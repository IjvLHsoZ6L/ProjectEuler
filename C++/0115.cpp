// 0115.cpp
#include <iostream>
using namespace std;

int main() {

    int m = 50;

    int size = 1000;

    int ways[size];

    int target = 1e6;

    for ( int l = 0; l < m; l++ )
        ways[l] = 1;

    bool exceed = false;
    for ( int l = m; not exceed; l++ ) {

        ways[l] = ways[l - 1];

        for ( int b = m; b + 1 <= l; b++ )
            ways[l] += ways[l - b - 1];

        ways[l] += ways[0];

        if ( ways[l] > target ) {

            exceed = true;

            cout << l << endl;
        }
    }

    return 0;
}
