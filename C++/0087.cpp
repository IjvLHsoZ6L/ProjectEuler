// 087.cpp
#include <iostream>
using namespace std;

int main() {

    int PRIME = 1e4;
    bool prime[PRIME];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < PRIME; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < PRIME; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < PRIME; j++ )
                prime[i*j] = false;

    int p[PRIME];
    int primes = 0;
    for ( int i = 0; i < PRIME; i++ ) {
        if ( prime[i] ) {
            p[primes] = i;
            primes++;
        }
    }

    const int MAX = 50e6;
    static bool appear[MAX];
    for ( int i = 0; i < MAX; i++ )
        appear[i] = false;

    for ( int i = 0; p[i]*p[i] < MAX; i++ )
        for ( int j = 0; p[i]*p[i] + p[j]*p[j]*p[j] < MAX; j++ )
            for ( int k = 0; p[i]*p[i] + p[j]*p[j]*p[j] + p[k]*p[k]*p[k]*p[k] < MAX; k++ )
                appear[p[i]*p[i] + p[j]*p[j]*p[j] + p[k]*p[k]*p[k]*p[k]] = true;

    int cnt = 0;
    for ( int i = 0; i < MAX; i++ )
        cnt += appear[i] ? 1 : 0;

    cout << cnt << endl;

    return 0;
}
