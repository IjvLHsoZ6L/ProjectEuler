// 0035.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        for ( int j = i; i*j < target; j++ )
            prime[i*j] = false;

    int cnt = 0;
    int d = 1;
    int unit = 1;
    for ( int n = 2; n < target; n++ ) {

        if ( not (n < 10*unit) ) {
            d++;
            unit *= 10;
        }

        if ( prime[n] ) {

            int N = n;
            bool circular = true;
            for ( int i = 1; i < d; i++ ) {
                int a = N % 10;
                N = a*unit + N/10;
                circular and_eq prime[N];
            }

            if ( circular )
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
