// 0128.cpp
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

    int target = 2000;
    int cnt = 2;
    for ( int r = 2; cnt < target; r++ ) {

        if ( prime[6 * r - 1] and prime[6 * r + 1] and prime[12 * r + 5] ) {
            cnt++;
            if ( cnt == target )
                cout << 1 + (long long) 6 * r * (r - 1) / 2 + 1 << endl;
        }

        if ( prime[6 * r - 1] and prime[6 * r + 5] and prime[12 * r - 7] ) {
            cnt++;
            if ( cnt == target )
                cout << 1 + (long long) 6 * r * (r - 1) / 2 + 6 * r << endl;
        }

    }

    return 0;
}
