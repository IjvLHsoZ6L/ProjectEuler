// 074.cpp
#include <iostream>
using namespace std;

int fact[10];

int sumfac(int n) {
    int sum = 0;
    while ( n > 0 ) {
        sum += fact[n%10];
        n /= 10;
    }
    return sum;
}

int main() {

    fact[0] = 1;
    for ( int i = 1; i < 10; i++ )
        fact[i] = i * fact[i-1];

    const int MAX = 1000000;
    const int SIZE = 6*1*2*3*4*5*6*7*8*9 + 1;

    static int length[SIZE];
    for ( int n = 0; n < SIZE; n++ )
        length[n] = 0;

    for ( int n = 0; n < SIZE; n++ )
        if ( sumfac(n) == n )
            length[n] = 1;

    length[169] = length[363600] = length[1454] = 3;
    length[871] = length[45361] = 2;
    length[872] = length[45362] = 2;

    for ( int n = 0; n < MAX; n++ ) {

        int l = 0;
        int N = n;
        while ( length[N] == 0 ) {
            l++;
            N = sumfac(N);
        }
        l += length[N];

        N = n;
        for ( int k = l; length[N] == 0; k-- ) {
            length[N] = k;
            N = sumfac(N);
        }
    }

    int max = 0;
    for ( int n = 0; n < MAX; n++ )
        if ( max < length[n] )
            max = length[n];

    int cnt = 0;
    for ( int n = 0; n < MAX; n++ )
        if ( length[n] == max )
            cnt++;

    cout << cnt << endl;

    return 0;
}
