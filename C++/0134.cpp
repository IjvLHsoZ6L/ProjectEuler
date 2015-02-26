// 0134.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;
    int pmax = target + 100;
    bool prime[pmax];
    for ( int n = 2; n < pmax; n++ )
        prime[n] = true;
    for ( int n = 2; n * n < pmax; n++ )
        if ( prime[n] )
            for ( int m = n; m * n < pmax; m++ )
                prime[m * n] = false;

    long long sum = 0;
    int p1 = 5, p2 = 7, unit = 10;
    do {

        if ( unit <= p1 )
            unit *= 10;

        long long m = 1, index = p2 - 2, power = unit % p2;
        while ( index > 0 ) {
            if ( index % 2 == 1 )
                m = m * power % p2;
            index /= 2;
            power = power * power % p2;
        }

        sum += m * (p2 - p1) % p2 * unit + p1;

        p1 = p2;
        p2++;
        while ( not prime[p2] )
            p2++;
    } while ( p1 < target );

    cout << sum << endl;

    return 0;
}
