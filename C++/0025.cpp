// 0025.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1000;

    int max = 0, nmax;
    for ( int n = 2; n < target; n++ ) {

        int appear[n];
        for ( int i = 0; i < n; i++ )
            appear[i] = 0;

        int rest = 1;
        int cnt = 1;
        while ( rest != 0 and appear[rest] == 0 ) {
            appear[rest] = cnt;
            rest = (10 * rest) % n;
            cnt++;
        }

        if ( rest != 0 and cnt - appear[rest] > max ) {
            max = cnt - appear[rest];
            nmax = n;
        }
    }

    cout << nmax << endl;

    return 0;
}
