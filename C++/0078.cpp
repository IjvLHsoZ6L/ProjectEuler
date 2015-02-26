// 078.cpp
#include <iostream>
using namespace std;

int main() {

    const int modulo = 1e6;
    const int MAX = 60000;

    int p[MAX];
    p[0] = 1;

    int sum[MAX];
    sum[0] = 1;
    for ( int n = 1; n < MAX; n++ )
        sum[n] = 0;

    int ans = 0;
    bool detected = false;
    for ( int k = 1; (not detected) and (k < MAX); k++ ) {
        int w[MAX];
        for ( int n = 0; n < k; n++ )
            w[n] = p[n];

        p[k] = (sum[k] + p[0]) % modulo;

        if ( p[k] == 0 ) {
            detected = true;
            ans = k;
        }

        for ( int n = k; n < MAX; n++ ) {
            w[n] = (sum[n] + w[n - k]) % modulo;
            sum[n] = w[n];
        }
    }

    cout << ans << endl;

    return 0;
}
