// 061.cpp
#include <iostream>
using namespace std;

int P(int i, int n) {
    return n * ((i - 2) * n - i + 4) / 2;
}

int cat(int a, int b) {
    return a*100 + b;
}

int main() {

    bool type[8+1][10000];
    for ( int i = 3; i <= 8; i++ )
        for ( int j = 0; j < 10000; j++ )
            type[i][j] = false;
    for ( int i = 3; i <= 8; i++ )
        for ( int n = 1; P(i, n) < 10000; n++ )
            type[i][P(i, n)] = true;

    int frac5 = 1;
    for ( int k = 1; k <= 5; k++ )
        frac5 *= k;

    for ( int a = 0; a < frac5; a++ ) {

        int perm[5];
        int A = a;
        for ( int k = 1; k <= 5; k++ ) {
            perm[5-k] = A%k;
            A /= k;
        }

        int remain[5];
        for ( int k = 0; k < 5; k++ )
            remain[k] = 4 + k;

        int i[6];
        for ( int k = 0; k < 5; k++ ) {
            i[k+1] = remain[perm[k]];
            for ( int l = perm[k]; l+1 < 5; l++ )
                remain[l] = remain[l+1];
        }

        int p[6];
        for ( p[0] = 10; p[0] < 100; p[0]++ ) {
            for ( p[1] = 10; p[1] < 100; p[1]++ ) {
                if ( type[3][cat(p[0], p[1])] ) {
                    for ( p[2] = 10; p[2] < 100; p[2]++ ) {
                        if ( type[i[1]][cat(p[1], p[2])] ) {
                            for ( p[3] = 10; p[3] < 100; p[3]++ ) {
                                if ( type[i[2]][cat(p[2], p[3])] ) {
                                    for ( p[4] = 10; p[4] < 100; p[4]++ ) {
                                        if ( type[i[3]][cat(p[3], p[4])] ) {
                                            for ( p[5] = 10; p[5] < 100; p[5]++ ) {
                                                if ( type[i[4]][cat(p[4], p[5])] and type[i[5]][cat(p[5], p[0])] ) {
                                                    int sum = 0;
                                                    for ( int k = 0; k < 6; k++ )
                                                        sum += cat(p[k], p[(k+1)%6]);
                                                    cout << sum << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}
