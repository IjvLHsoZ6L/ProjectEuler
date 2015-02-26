// 077.cpp
#include <iostream>
using namespace std;

int main() {

    int MAX = 1e2;
    bool prime[MAX];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < MAX; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < MAX; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < MAX; j++ )
                prime[i*j] = false;

    int way[MAX][MAX];
    for ( int i = 0; i < MAX; i++ )
        way[0][i] = 1;

    bool detected = false;
    int ans = 0;
    for ( int n = 1; not detected; n++ ) {

        way[n][0] = 0;

        for ( int i = 1; i <= n; i++ ) {
            if ( prime[i] )
                way[n][i] = way[n - i][i] + way[n][i - 1];
            else
                way[n][i] = way[n][i - 1];
        }

        for ( int i = n + 1; i < MAX; i++ )
            way[n][i] = way[n][n];

        if ( way[n][n - 1] > 5000 ) {
            detected = true;
            ans = n;
        }
    }

    cout << ans << endl;

    return 0;
}
