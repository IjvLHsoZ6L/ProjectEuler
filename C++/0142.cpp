// 0142.cpp
#include <iostream>
using namespace std;

int main() {

    int minimum = 11e5;

    for ( int a = 1; 3*(a + 2) + a*a + (a + 1)*(a + 1) < minimum; a++ ) {

        int b = 1;

        for ( int c = a + 1; 3*(c + 1) + a*a + c*c < minimum; c++ ) {

            while ( a*a + b*b < c*c )
                b++;

            if ( a*a + b*b == c*c ) {

                int A = 1, B = 1, C = 1;

                for ( int x = c + 1; 3*x + a*a + c*c < minimum and 2*c <= a*a; x++ ) {

                    while ( A*A < 2*x + a*a )
                        A++;

                    while ( B*B < 2*x + c*c )
                        B++;

                    while ( C*C < 2*x + a*a + c*c )
                        C++;

                    if ( A*A == 2*x + a*a and B*B == 2*x + c*c and C*C == 2*x + a*a + c*c )
                        minimum = 3*x + a*a + c*c;
                }
            }
        }
    }

    cout << minimum << endl;

    return 0;
}
