// 070.cpp
#include <iostream>
using namespace std;

bool perm(int a, int b) {
    int A[10], B[10];
    for ( int i = 0; i < 10; i++ )
        A[i] = B[i] = 0;

    int N = a;
    while ( N > 0 ) {
        A[N%10]++;
        N /= 10;
    }
    N = b;
    while ( N > 0 ) {
        B[N%10]++;
        N /= 10;
    }

    bool coincide = true;
    for ( int i = 0; i < 10; i++ )
        coincide = coincide and (A[i] == B[i]);

    return coincide;
}

int main() {

    int pmax = 1e5;
    bool prime[pmax];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < pmax; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < pmax; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < pmax; j++ )
                prime[i*j] = false;

    int p[pmax];
    int primes = 0;
    for ( int i = 0; i < pmax; i++ ) {
        if ( prime[i] ) {
            p[primes] = i;
            primes++;
        }
    }

    int nsup = 1e7;
    int nres = 0;
    double ratiomin = 2.0;

    for ( int i = 0; i < primes and p[i]*p[i] < nsup; i++ ) {
        for ( int j = i; j < primes and p[i]*p[j] < nsup; j++ ) {
            int n = p[i]*p[j];
            int phi = (i < j) ? (p[i]-1)*(p[j]-1) : p[i]*(p[j]-1);
            double ratio = (double) n / phi;
            if ( perm(n, phi) ) {
                if ( ratio < ratiomin ) {
                    nres = n;
                    ratiomin = ratio;
                }
            }
        }
    }

    cout << nres << endl;

    return 0;
}
