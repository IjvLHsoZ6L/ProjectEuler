// 062.cpp
#include <iostream>
using namespace std;

static int digits[5];
static int appear[5][10];

void digit(long long n, int i) {

    digits[i] = 0;
    for ( int d = 0; d < 10; d++ )
        appear[i][d] = 0;

    long long N = n;
    while ( N > 0 ) {
        digits[i]++;
        appear[i][N%10]++;
        N /= 10;
    }

}

bool over(int i, int j) {
    return (digits[i] != digits[j]);
}

bool coincide(int i, int j) {
    bool forall = true;
    for ( int d = 0; d < 10; d++ )
        forall = forall and (appear[i][d] == appear[j][d]);
    return forall;
}

long long cube(int b) {
    return (long long)b*b*b;
}

int main() {

    bool detected = false;
    int b[5];

    b[0] = 0;
    do {
        b[0]++;
        digit(cube(b[0]), 0);
        {

            b[1] = b[0];
            do {
                b[1]++;
                digit(cube(b[1]), 1);
                if  ( coincide(0, 1) ) {

                    b[2] = b[1];
                    do {
                        b[2]++;
                        digit(cube(b[2]), 2);
                        if ( coincide(1, 2) ) {

                            b[3] = b[2];
                            do {
                                b[3]++;
                                digit(cube(b[3]), 3);
                                if ( coincide(2, 3) ) {

                                    b[4] = b[3];
                                    do {
                                        b[4]++;
                                        digit(cube(b[4]), 4);
                                        if ( coincide(3, 4) ) {

                                            detected = true;
                                            cout << cube(b[0]) << endl;
                                        }
                                    } while ( (not detected) and (not over(3, 4)) );
                                }
                            } while ( (not detected) and (not over(2, 3)) );
                        }
                    } while ( (not detected) and (not over(1, 2)) );
                }
            } while ( (not detected) and (not over(0, 1)) );
        }
    } while ( not detected );

    return 0;
}
