// 069.cpp
#include <iostream>
using namespace std;

int main() {

    int pmax = 1e4;
    bool prime[pmax];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < pmax; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < pmax; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < pmax; j++ )
                prime[i*j] = false;

    int max = 1e6;
    int prod = 1;
    int p = 1;
    while ( prod * p < max ) {
        prod *= p;
        do {
            p++;
        } while ( not prime[p] );
    }

    cout << prod << endl;

    return 0;
}
