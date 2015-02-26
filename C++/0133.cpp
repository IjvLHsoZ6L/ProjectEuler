// 0133.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e5;
    bool prime[target];
    for ( int n = 2; n < target; n++ )
        prime[n] = true;
    for ( int n = 2; n * n < target; n++ )
        if ( prime[n] )
            for ( int m = n; m * n < target; m++ )
                prime[m * n] = false;


    int sum = 0;
    for ( int n = 2; n < target; n++ ) {
        if ( prime[n] ) {

            if ( n == 2 or n == 5 )
                sum += n;

            else {

                int k = 1;
                for ( int R = 1; R > 0; k++ )
                    R = (10 * R + 1) % n;

                while ( k % 2 == 0 )
                    k /= 2;

                while ( k % 5 == 0 )
                    k /= 5;

                if ( k > 1 )
                    sum += n;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
