// 060.cpp
#include <iostream>
using namespace std;

const int MAX = 1e4;
const int PMAX = MAX*MAX;

bool prime[PMAX];

int p_[MAX];
int primes;

bool primecat[MAX][MAX];

int cat(int a, int b) {
    int unit = 1;
    while ( not (b < unit) )
        unit *= 10;
    return a*unit + b;
}

int main() {

    prime[0] = prime[1] = false;
    for ( int i = 2; i < PMAX; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < PMAX; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < PMAX; j++ )
                prime[i*j] = false;

    primes = 0;
    for ( int i = 0; i < MAX; i++ ) {
        if ( prime[i] ) {
            p_[primes] = i;
            primes++;
        }
    }

    for ( int a = 0; a < primes; a++ )
        for ( int b = a; b < primes; b++ )
            primecat[a][b] = prime[cat(p_[a], p_[b])] and prime[cat(p_[b], p_[a])];

    int min = 5*MAX;
    for ( int a0 = 0; a0 < primes; a0++ ) {
        for ( int a1 = a0+1; a1 < primes; a1++ ) {
            if ( primecat[a0][a1] ) {
                for ( int a2 = a1+1; a2 < primes; a2++ ) {
                    if ( primecat[a0][a2] and primecat[a1][a2] ) {
                        for ( int a3 = a2+1; a3 < primes; a3++ ) {
                            if ( primecat[a0][a3] and primecat[a1][a3] and primecat[a2][a3] ) {
                                for ( int a4 = a3+1; a4 < primes; a4++ ) {
                                    if ( primecat[a0][a4] and primecat[a1][a4] and primecat[a2][a4] and primecat[a3][a4] ) {
                                        int sum = p_[a0] + p_[a1] + p_[a2] + p_[a3] + p_[a4];
                                        if ( sum < min ) {
                                            min = sum;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << min << endl;

    return 0;
}
