// 0014.cpp
#include <iostream>
using namespace std;

long long collatz(long long n) {
    if ( n % 2 == 0 )
        return n / 2;
    else
        return 3*n + 1;
}

int main() {

    int target = 1e6;

    int length[target];
    length[1] = 1;
    for ( int i = 2; i < target; i++ )
        length[i] = 0;

    for ( int start = 1; start < target; start++ ) {
        if ( length[start] == 0 ) {

            int cnt = 0;
            long long n = start;
            while ( not (n < target and length[n] > 0) ) {
                n = collatz(n);
                cnt++;
            }
            cnt += length[n];

            n = start;
            while ( not (n < target and length[n] > 0) ) {
                if ( n < target )
                    length[n] = cnt;
                n = collatz(n);
                cnt--;
            }
        }
    }

    int max = 0, startmax = 0;
    for ( int start = 1; start < target; start++ ) {
        if ( length[start] > max ) {
            max = length[start];
            startmax = start;
        }
    }

    cout << startmax << endl;

    return 0;
}
