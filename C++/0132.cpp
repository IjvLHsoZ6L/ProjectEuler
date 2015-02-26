// 0132.cpp
#include <iostream>
using namespace std;

int main() {

    int pmax = 1e6;
    bool prime[pmax];
    for ( int i = 2; i < pmax; i++ )
        prime[i] = true;
    for ( int i = 2; i * i < pmax; i++ )
        if ( prime[i] )
            for ( int j = i; i * j < pmax; j++ )
                prime[i * j] = false;

    int target = 1e9;

    int cnt = 0;
    int sum = 0;
    for ( int p = 7; cnt < 40; p++ ) {
        if ( prime[p] ) {

            int k = 1;
            for ( int R = 1; R > 0; k++ )
                R = (R * 10 + 1) % p;

            if ( target % k == 0 ) {
                cnt++;
                sum += p;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
