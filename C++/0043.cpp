// 0043.cpp
#include <iostream>
using namespace std;

int main() {

    int fact10 = 1*2*3*4*5*6*7*8*9*10;

    long long sum = 0;
    for ( int n = 0; n < fact10; n++ ) {

        int d[10 + 1];
        int N = n;
        for ( int k = 1; k <= 10; k++ ) {
            d[10 - k + 1] = N % k;
            N /= k;
        }

        bool appear[10];
        for ( int k = 0; k < 10; k++ )
            appear[k] = false;

        for ( int i = 1; i <= 10; i++ ) {

            int k = -1;
            for ( int cnt = 0; cnt <= d[i]; cnt++ ) {
                k++;
                while ( appear[k] )
                    k++;
            }

            d[i] = k;
            appear[k] = true;
        }

        bool property = true;
        property and_eq ((d[2]*100 + d[3]*10 + d[4]) % 2 == 0);
        property and_eq ((d[3]*100 + d[4]*10 + d[5]) % 3 == 0);
        property and_eq ((d[4]*100 + d[5]*10 + d[6]) % 5 == 0);
        property and_eq ((d[5]*100 + d[6]*10 + d[7]) % 7 == 0);
        property and_eq ((d[6]*100 + d[7]*10 + d[8]) % 11 == 0);
        property and_eq ((d[7]*100 + d[8]*10 + d[9]) % 13 == 0);
        property and_eq ((d[8]*100 + d[9]*10 + d[10]) % 17 == 0);

        if ( property ) {

            long long number = 0;
            for ( int i = 1; i <= 10; i++ ) {
                number *= 10;
                number += d[i];
            }

            sum += number;
        }
    }

    cout << sum << endl;

    return 0;
}
