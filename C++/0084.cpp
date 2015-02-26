// 084.cpp
#include <iostream>
using namespace std;

double max(double a, double b) {
    return (a > b) ? a : b;
}

double abs(double a) {
    return (a > 0) ? a : -a;
}

int main() {

    int dice = 4;

    double prob[40];
    prob[0] = 1.0;
    for ( int i = 1; i < 40; i++ )
        prob[i] = 0.0;

    double delta;
    do {

        double next[40];
        for ( int i = 0; i < 40; i++ )
            next[i] = 0;

        for ( int i = 0; i < 40; i++ ) {
            for ( int d1 = 1; d1 <= dice; d1++ ) {
                for ( int d2 = 1; d2 <= dice; d2++ ) {
                    int here = (i + d1 + d2) % 40;
                    double probhere = prob[i] / (dice*dice);
                    // GO2JAIL
                    if ( here == 30 ) {
                        next[10] += probhere;
                    }
                    // CC
                    else if ( here == 2 or here == 17 or here == 33 ) {
                        // GO
                        next[ 0] += probhere / 16;
                        // JAIL
                        next[10] += probhere / 16;
                        // others
                        next[here] += probhere / 16 * 14;
                    }
                    // CH
                    else if ( here == 7 or here == 22 or here == 36 ) {
                        // GO
                        next[ 0] += probhere / 16;
                        // JAIL
                        next[10] += probhere / 16;
                        // C1
                        next[11] += probhere / 16;
                        // E3
                        next[24] += probhere / 16;
                        // H2
                        next[39] += probhere / 16;
                        // R1
                        next[ 5] += probhere / 16;
                        // next R
                        if ( here == 7 )
                            next[15] += probhere / 16 * 2;
                        else if ( here == 22 )
                            next[25] += probhere / 16 * 2;
                        else if ( here == 36 )
                            next[ 5] += probhere / 16 * 2;
                        // next U
                        if ( here == 7 )
                            next[12] += probhere / 16;
                        else if ( here == 22 )
                            next[28] += probhere / 16;
                        else if ( here == 36 )
                            next[12] += probhere / 16;
                        // -3
                        next[(here - 3) % 40] += probhere / 16;
                        // others
                        next[here] += probhere / 16 * 6;
                    }
                    else {
                        next[here] += probhere;
                    }
                }
            }
        }

        delta = 0;
        for ( int i = 0; i < 40; i++ ) {
            delta = max(delta, abs(next[i] - prob[i]));
            prob[i] = next[i];
        }

    } while ( delta > 1e-6 );

    int ans = 0;
    for ( int k = 0; k < 3; k++ ) {
        double max = 0;
        int imax = 0;
        for ( int i = 0; i < 40; i++ ) {
            if ( max < prob[i] ) {
                max = prob[i];
                imax = i;
            }
        }
        ans = 100*ans + imax;
        prob[imax] = 0;
    }

    cout << ans << endl;

    return 0;
}
