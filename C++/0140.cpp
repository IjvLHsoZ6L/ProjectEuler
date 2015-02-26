// 0140.cpp
#include <iostream>
using namespace std;

int main() {

    int cnt = 0;
    long long sum = 0;
    long long a = 1;
    long long r = 1;
    while ( cnt < 6 ) {

        while ( r*r < 5*a*a + 14*a + 1 )
            r++;

        if ( r*r == 5*a*a + 14*a + 1 ) {
            cnt++;

            int subcnt = 0;
            long long n = 5*a + 7;
            long long d = r;
            while ( subcnt < 5 ) {

                subcnt++;
                sum += (n - 7) / 5;

                long long nn = 161*n + 360*d;
                long long dd = 72*n + 161*d;
                n = nn;
                d = dd;
            }
        }

        a++;
    }

    cout << sum << endl;

    return 0;
}
