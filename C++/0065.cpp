// 065.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 128;
    int seq[size];
    seq[1] = 2;
    for ( int i = 1; 3*i < size; i++ ) {
        seq[3*i-1] = 1;
        seq[3*i] = 2*i;
        seq[3*i+1] = 1;
    }

    int target = 100;

    int dmax = 100;
    int numer[dmax], denom[dmax];
    for ( int d = 0; d < dmax; d++ )
        numer[d] = denom[d] = 0;
    numer[0] = seq[target];
    denom[0] = 1;

    for ( int n = target-1; n > 0; n-- ) {
        int temp[dmax];
        for ( int d = 0; d < dmax; d++ )
            temp[d] = denom[d];

        for ( int d = 0; d < dmax; d++ )
            denom[d] = numer[d];

        for ( int d = 0; d < dmax; d++ )
            numer[d] = seq[n]*denom[d] + temp[d];

        for ( int d = 0; d+1 < dmax; d++ ) {
            numer[d+1] += numer[d]/10;
            numer[d] %= 10;
        }
    }

    int sum = 0;
    for ( int d = 0; d < dmax; d++ )
        sum += numer[d];
    cout << sum << endl;

    return 0;
}
