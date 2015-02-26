// 0046.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e4;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    bool sum[target];
    for ( int i = 0; i < target; i++ )
        sum[i] = false;

    for ( int p = 0; p < target; p++ )
        if ( prime[p] )
            for ( int i = 1; p + 2*i*i < target; i++ )
                sum[p + 2*i*i] = true;

    int odd = 3;
    while ( prime[odd] or sum[odd] )
        odd += 2;

    cout << odd << endl;

    return 0;
}
