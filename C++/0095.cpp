// 095.cpp
#include <iostream>
using namespace std;

int main() {

    const int MAX = 1e6;

    static int prime[MAX+1];
    prime[0] = prime[1] = false;
    for ( int i = 2; i <= MAX; i++ )
        prime[i] = true;
    for ( int i = 2; i*i <= MAX; i++ )
        if ( prime[i] )
            for ( int j = i; i*j <= MAX; j++ )
                prime[i*j] = false;

    static int p[MAX], primes = 0;
    for ( int i = 0; i <= MAX; i++ ) {
        if ( prime[i] ) {
            p[primes] = i;
            primes++;
        }
    }

    // sum of the proper divisors
    static int spd[MAX+1];
    for ( int n = 0; n <= MAX; n++ )
        spd[n] = 1;

    for ( int i = 0; i < primes; i++ ) {
        long long power = p[i];
        long long sumprev = 1;
        long long sum = 1 + p[i];
        while ( power <= MAX ) {
            for ( int k = 1; k*power <= MAX; k++ ) {
                spd[k*power] /= sumprev;
                spd[k*power] *= sum;
            }
            power *= p[i];
            sumprev = sum;
            sum += power;
        }
    }

    for ( int n = 0; n <= MAX; n++ )
        spd[n] -= n;

    //
    static bool checked[MAX+1];
    checked[0] = checked[1] = true;
    for ( int n = 2; n <= MAX; n++ )
        checked[n] = (spd[n] > MAX);

    bool changed;
    do {
        changed = false;
        for ( int n = 0; n <= MAX; n++ ) {
            if ( (not checked[n]) and checked[spd[n]] ) {
                changed = true;
                checked[n] = true;
            }
        }
    } while ( changed );

    bool remain = true;
    int ans = 0;
    for ( int l = 1; remain; l++ ) {
        remain = false;
        int min = MAX+1;
        for ( int n = 0; n <= MAX; n++ ) {
            if ( not checked[n] ) {
                remain = true;

                int m = n;
                for ( int cnt = 0; cnt < l; cnt++ )
                    m = spd[m];

                if ( m == n ) {
                    for ( int cnt = 0; cnt < l; cnt++ ) {
                        if ( m < min )
                            min = m;
                        checked[m] = true;
                        m = spd[m];
                    }
                } else if ( checked[m] ) {
                    m = n;
                    while ( not checked[m] ) {
                        checked[m] = true;
                        m = spd[m];
                    }
                }
            }
        }
        if ( min <= MAX )
            ans = min;
    }

    cout << ans << endl;

    return 0;
}
