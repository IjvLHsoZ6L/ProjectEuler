// 088.cpp
#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b ? a : b);
}
int main() {

    const int MAX = 12000;
    const int INF= 0xFFFF;
    // ml(p, t) = min{ l | p factors l numbers with sum l+t }
    static int ml[2*MAX+1][MAX+1];
    for ( int p = 1; p <= 2*MAX; p++ )
        for ( int t = 0; t <= MAX; t++ )
            ml[p][t] =  INF;

    ml[1][0] = 0;
    for ( int p = 1; p <= 2*MAX; p++ )
        for ( int t = 0; t <= MAX; t++ )
            if ( ml[p][t] < INF )
                for ( int c = 2; p*c <= 2*MAX and t+c-1 <= MAX; c++ )
                    ml[p*c][t+c-1] = min(ml[p*c][t+c-1], ml[p][t] + 1);

    // appear(p) <=> p appears as the minimal product-sum for 2 <= k <= MAX
    bool appear[2*MAX+1];
    for ( int p = 1; p <= 2*MAX; p++ )
        appear[p] = false;

    for ( int l = 2; l <= MAX; l++ ) {
        int p = l;
        while ( ml[p][p-l] > l )
            p++;

        appear[p] = true;
    }

    int sum = 0;
    for ( int p = 1; p <= 2*MAX; p++ )
        if ( appear[p] )
            sum += p;

    cout << sum << endl;

    return 0;
}
