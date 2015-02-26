// 068.cpp
#include <iostream>
using namespace std;

int main() {

    int frac10 = 1;
    for ( int n = 1; n <= 10; n++ )
        frac10 *= n;

    long long catmax = 0;
    for ( int n = 0; n < frac10; n++ ) {

        int a[10+1];
        int N = n;
        for ( int k = 1; k <= 10; k++ ) {
            a[10-k] = N % k;
            N /= k;
        }

        bool appear[10+1];
        for ( int k = 1; k <= 10; k++ )
            appear[k] = false;

        for ( int i = 0; i < 10; i++ ) {
            int k = 0;
            int cnt = 0;
            while ( cnt <= a[i] ) {
                k++;
                if ( not appear[k] )
                    cnt++;
            }
            a[i] = k;
            appear[k] = true;
        }

        bool forall = true;
        for ( int i = 1; i < 5; i++ )
            forall = forall and (a[0] < a[i]);

        if ( forall ) {

            int b[5][3];
            for ( int i = 0; i < 5; i++ ) {
                b[i][0] = a[i];
                b[i][1] = a[5+i];
                b[i][2] = a[5+(i+1)%5];
            }

            int sum = b[0][0] + b[0][1] + b[0][2];

            bool forall = true;
            for ( int i = 1; i< 5; i++ )
                forall = forall and (sum == b[i][0] + b[i][1] + b[i][2]);

            if ( forall ) {

                long long cat = 0;
                int digits = 0;
                for ( int i = 0; i < 5; i++ ) {
                    for ( int j = 0; j < 3; j++ ) {
                        if ( b[i][j] == 10 ) {
                            cat = cat*100 + b[i][j];
                            digits += 2;;
                        }
                        else {
                            cat = cat*10 + b[i][j];
                            digits += 1;
                        }
                    }
                }

                if ( digits == 16 and catmax < cat )
                    catmax = cat;
            }
        }

    }

    cout << catmax << endl;

    return 0;
}
