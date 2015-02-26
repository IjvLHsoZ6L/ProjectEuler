// 055.cpp
#include <iostream>
using namespace std;

long long reverse(long long n) {
    long long N = n;
    long long M = 0;
    while ( N > 0 ) {
        M = M*10 + N%10;
        N /= 10;
    }
    return M;
}

int main() {

    int nmax = 1e4;

    int cnt = 0;
    for ( int n = 1; n < nmax; n++ ) {
        long long N = n;
        bool Lychrel = true;
        for ( int i = 0; Lychrel and i < 29; i++ ) {
            N += reverse(N);
            if ( N < 0 )
                throw;
            if ( N == reverse(N) )
                Lychrel = false;
        }
        if ( Lychrel )
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}
