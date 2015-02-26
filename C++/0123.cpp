// 0123.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;

    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    int p[target];

    int nmax = 0;
    for ( int i = 0; i < target; i++ )
        if ( prime[i] )
            p[++nmax] = i;

    long long criterion = 1e10;
    bool exceed = false;
    for ( int n = 1; n <= nmax and not exceed; n++ ) {

        long long square = (long long) p[n] * p[n];

        long long term1 = 1, term2 = 1;
        for ( int i = 0; i < n; i++ ) {
            term1 = term1 * (p[n] - 1) % square;
            term2 = term2 * (p[n] + 1) % square;
        }

        if ( (term1 + term2) % square > criterion ) {
            exceed = true;
            cout << n << endl;
        }
    }

    return 0;
}
