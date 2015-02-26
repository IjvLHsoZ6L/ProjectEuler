// 0027.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1000;
    int range = 2*target*target;

    bool prime[range];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < range; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < range; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < range; j++ )
                prime[i*j] = false;

    int max = 0, amax, bmax;
    for ( int a = - target + 1; a < target; a++ )
        for ( int b = - target + 1; b < target; b++ ) {

            int n = 0;
            while ( n*n + a*n + b >= 0 and prime[n*n + a*n + b] )
                n++;

            if ( max < n ) {
                max = n;
                amax = a;
                bmax = b;
            }
        }

    cout << amax * bmax << endl;

    return 0;
}
