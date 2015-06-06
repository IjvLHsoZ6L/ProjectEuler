// 0050.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    bool prime[target];
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    int p[target], primes = 0;
    for ( int i = 2; i < target; i++ ) {
        if ( prime[i] ) {
            p[primes] = i;
            primes++;
        }
    }

    int maxlength = 0, maxsum = 0;
    for ( int start = 0; maxlength * p[start] < target; start++ ) {

        int sum = p[start];
        for ( int length = 1; sum < target; length++ ) {

            if ( prime[sum] and length > maxlength ) {
                maxlength = length;
                maxsum = sum;
            }

            sum += p[start + length];
        }
    }

    cout << maxsum << endl;

    return 0;
}
