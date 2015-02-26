// 0037.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    int prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    int sum = 0;
    for ( int n = 10; n < target; n++ ) {
        if ( prime[n] ) {

            bool truncatable = true;
            int unit = 10;
            while ( unit <= n ) {
                truncatable and_eq prime[n / unit] and prime[n % unit];
                unit *= 10;
            }

            if ( truncatable )
                sum += n;
        }
    }

    cout << sum << endl;

    return 0;
}
