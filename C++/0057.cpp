// 057.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 400;
    int numer[size], denom[size];
    int dign = 1, digd = 1;
    numer[0] = 3, denom[0] = 2;
    for ( int i = 1; i < size; i++ )
        numer[i] = denom[i] = 0;

    int cnt = 0;
    for ( int k = 0; k < 1000; k++ ) {

        if ( dign > digd )
            cnt++;

        for ( int i = 0; i < size; i++ ) {
            numer[i] = numer[i] + 2*denom[i];
            denom[i] = numer[i] - denom[i];
        }
        for ( int i = 0; i+1 < size; i++ ) {
            numer[i+1] += numer[i]/10;
            numer[i] %= 10;
            denom[i+1] += denom[i]/10;
            denom[i] %= 10;
        }
        if ( numer[dign] > 0 )
            dign++;
        if ( denom[digd] > 0 )
            digd++;

        if ( dign == size )
            throw;
    }

    cout << cnt << endl;

    return 0;
}
