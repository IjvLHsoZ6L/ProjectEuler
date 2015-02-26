// 0130.cpp
#include <iostream>
using namespace std;

int main() {

    int pmax = 1e6;
    bool prime[pmax];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < pmax; i++ )
        prime[i] = true;
    for ( int i = 2; i * i < pmax; i++ )
        if ( prime[i] )
            for ( int j = i; i * j < pmax; j++ )
                prime[i * j] = false;

    int target = 25;
    int sum = 0;
    int cnt = 0;
    for ( int n = 2; cnt < target; n++ ) {
        if ( n % 2 > 0 and n % 5 > 0 and not prime[n] ) {

            int k = 1;
            for ( int R = 1; R > 0; k++ )
                R = (10 * R + 1) % n;

            if ( (n - 1) % k == 0 ) {
                sum += n;
                cnt++;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
