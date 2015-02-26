// 072.cpp
#include <iostream>
using namespace std;

int main() {

    const int MAX = 1000000;

    bool prime[MAX+1];
    prime[0] = prime[1] = false;
    for ( int i = 2; i <= MAX; i++ )
        prime[i] = true;
    for ( int i = 2; i*i <= MAX; i++ )
        if ( prime[i] )
            for ( int j = 2; i*j <= MAX; j++ )
                prime[i*j] = false;

    int p_[MAX+1];
    int primes = 0;
    for ( int p = 0; p <= MAX; p++ ) {
        if ( prime[p] ) {
            p_[primes] = p;
            primes++;
        }
    }

    static int phi[MAX+1];
    for ( int n = 0; n <= MAX; n++ )
        phi[n] = n;
    for ( int i = 0; i < primes; i++ ) {
        for ( int j = 1; p_[i]*j <= MAX; j++ ) {
            phi[p_[i]*j] /= p_[i];
            phi[p_[i]*j] *= p_[i] - 1;
        }
    }

    long long sum = 0;
    for ( int n = 2; n <= MAX; n++ )
        sum += phi[n];

    cout << sum << endl;

    return 0;
}
