// 0049.cpp
#include <iostream>
using namespace std;

int main() {

    int start = 1e3, target = 1e4;
    int one = 1487;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    for ( int first = start; first < target; first++ ) {
        if ( prime[first] ) {
            for ( int delta = 1; first + 2*delta < target; delta++ ) {
                if ( prime[first + delta] and prime[first + 2*delta] ) {

                    int appear[3][10];
                    for ( int i = 0; i < 3; i++ )
                        for ( int k = 0; k < 10; k++ )
                            appear[i][k] = 0;

                    for ( int i = 0; i < 3; i++ ) {
                        int N = first + i*delta;
                        while ( N > 0 ) {
                            appear[i][N % 10]++;
                            N /= 10;
                        }
                    }

                    int coincide = true;
                    for ( int k = 0; k < 10; k++ )
                        coincide and_eq appear[0][k] == appear[1][k] and appear[1][k] == appear[2][k];

                    if ( coincide and first != one )
                        cout << first << first + delta << first + 2*delta << endl;
                }
            }
        }
    }

    return 0;
}
