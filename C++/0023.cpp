// 0023.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 28123;

    bool prime[target + 1];
    prime[0] = prime[1] = false;
    for ( int i = 2; i <= target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i <= target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j <= target; j++ )
                prime[i*j] = false;

    int d[target + 1];
    for ( int n = 1; n <= target; n++ )
        d[n] = 1;

    int p = 2;
    do {

        int sumofpowers[target + 1];
        for ( int k = 1; k * p <= target; k++ )
            sumofpowers[k * p] = 1 + p;

        int power = p * p;
        while ( power <= target ) {

            for ( int k = 1; k * power <= target; k++ )
                sumofpowers[k * power] += power;

            power *= p;
        }

        for ( int k = 1; k * p <= target; k++ )
            d[k * p] *= sumofpowers[k * p];

        p++;
        while ( p <= target and not prime[p] )
            p++;

    } while ( p <= target );

    for ( int n = 1; n <= target; n++ )
        d[n] -= n;

    bool sumoftwo[target + 1];
    for ( int n = 1; n <= target; n++ )
        sumoftwo[n] = false;

    for ( int m = 1; m + m <= target; m++ )
        if ( d[m] > m )
            for ( int n = m; m+ n <= target; n++ )
                if ( d[n] > n )
                    sumoftwo[m + n] = true;

    int sum = 0;
    for ( int n = 1; n <= target; n++ )
        if ( not sumoftwo[n] )
            sum += n;

    cout << sum << endl;

    return 0;
}
