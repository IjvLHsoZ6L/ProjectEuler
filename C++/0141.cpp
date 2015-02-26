// 0141.cpp
#include <iostream>
using namespace std;

int main() {

    long long target = 1e12;
    long long sum = 0;

    for ( long long a = 1; a <= 3; a++ ) {
        for ( long long b = 1; a*b*(a*(b + 1)*(b + 1)*(b + 1) + b) < target; b++ ) {

            long long m = 1;
            for ( long long c = b + 1; a*b*(a*c*c*c + b) < target; c++ ) {

                while ( m*m < a*b*(a*c*c*c + b) )
                    m++;

                if ( m*m == a*b*(a*c*c*c + b) )
                    sum += m*m;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
