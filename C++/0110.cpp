// 0110.cpp
#include <iostream>
using namespace std;

const int psize = 1e4;

bool prime[psize];
int p[psize], primes;

void primeformat() {

    prime[0] = prime[1] = false;
    for ( int i = 2; i < psize; i++ )
        prime[i] = true;

    for ( int i = 2; i*i < psize; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < psize; j++ )
                prime[i*j] = false;

    primes = 0;
    for ( int i = 0; i < psize; i++ )
        if ( prime[i] )
            p[primes++] = i;

    return;
}

long long maximum = 1e16;

int target = 2 * 4e6 - 1;

void sub(int i, int kmax, int divisors, long long power) {

    int k = 1;
    long long pik = p[i];

    while ( divisors * (2 * k + 1) <= target and power * pik < maximum ) {

        sub(i + 1, k, divisors * (2 * k + 1), power * pik);

        k++;
        pik *= p[i];
    }

    if ( divisors * (2 * k + 1) > target and power * pik < maximum )
        maximum = power * pik;

    return;
}

int main() {

    primeformat();

    sub(0, 10, 1, 1);

    cout << maximum << endl;

    return 0;
}
