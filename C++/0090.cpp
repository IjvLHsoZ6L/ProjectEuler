// 090.cpp
#include <iostream>
using namespace std;

int main() {

    bool arrange[210][10];
    int arranges = 0;
    int d[6];
    for ( d[0] = 0; d[0] < 10; d[0]++ ) {
        for ( d[1] = d[0]+1; d[1] < 10; d[1]++ ) {
            for ( d[2] = d[1]+1; d[2] < 10; d[2]++ ) {
                for ( d[3] = d[2]+1; d[3] < 10; d[3]++ ) {
                    for ( d[4] = d[3]+1; d[4] < 10; d[4]++ ) {
                        for ( d[5] = d[4]+1; d[5] < 10; d[5]++ ) {

                            for ( int k = 0; k <= 9; k++ )
                                arrange[arranges][k] = false;

                            for ( int i = 0; i < 6; i++ )
                                arrange[arranges][d[i]] = true;

                            arrange[arranges][6] = arrange[arranges][9] = arrange[arranges][6] or arrange[arranges][9];

                            arranges++;
                        }
                    }
                }
            }
        }
    }

    int cnt = 0;
    for ( int m = 0; m < arranges; m++ ) {
        for ( int n = m; n < arranges; n++ ) {

            bool forall = true;
            for ( int i = 1; i <= 9; i++ ) {
                int d1 = i*i/10, d2 = i*i%10;
                forall and_eq ((arrange[m][d1] and arrange[n][d2]) or (arrange[m][d2] and arrange[n][d1]));
            }

            if ( forall )
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
