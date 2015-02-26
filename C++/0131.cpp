// 0131.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;
    bool prime[target];
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i * i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i * j < target; j++ )
                prime[i * j] = false;

    int cnt = 0;
    for ( int p = 2; p < target; p++ ) {
        if ( prime[p] ) {

            bool detected = false;
            int l = 2;
            for ( int k = 1; not detected and 3*k*k + 3*k + 1 <= p; k++ ) {
                while ( l*l*l < k*k*k + p )
                    l++;
                if ( l*l*l == k*k*k + p )
                    detected = true;
            }

            if ( detected )
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
