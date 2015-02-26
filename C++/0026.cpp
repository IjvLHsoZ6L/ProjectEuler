// 0026.cpp
#include <iostream>
using namespace std;

int main() {

    int max = 0;
    int dmax = 0;

    for ( int d = 2; d < 1000; d++ ) {
        int appear[d];
        for ( int i = 0; i < d; i++ )
            appear[i] = 0;

        int cnt = 0;
        int rest = 1;
        while ( rest > 0 and  appear[rest] == 0 ) {
            appear[rest] = cnt;
            rest = 10*rest % d;
            cnt++;
        }

        if ( rest > 0 and max < cnt - appear[rest] ) {
            max = cnt - appear[rest];
            dmax = d;
        }
    }

    cout << dmax << endl;

    return 0;
}
