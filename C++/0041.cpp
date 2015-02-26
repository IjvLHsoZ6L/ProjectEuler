// 041.cpp
#include <iostream>
using namespace std;

int main() {

    int nmax = 0;

    for ( int n = 1234567; n <= 7654321; n++ ) {

        int app[10];
        for ( int i = 0; i < 10; i++ )
            app[i] = 0;

        int N = n;
        while ( N > 0 ) {
            app[N%10]++;
            N /= 10;
        }

        bool pan = true;
        for ( int i = 1; i <= 7; i++ ) {
            pan = pan and (app[i] == 1);
        }

        if ( pan ) {
            bool prime = true;
            for ( int i = 2; prime and i*i <= n; i++ ) {
                if ( n % i == 0 ) {
                    prime = false;
                }
            }

            if ( prime )
                nmax = n;
        }
    }

    cout << nmax << endl;

    return 0;
}
