// 0112.cpp
#include <iostream>
using namespace std;

int main() {

    int n = 0, cnt = 0;

    do {
        n++;

        bool increasing = true;
        int previous = n % 10;
        int N = n / 10;
        while ( N > 0 ) {
            increasing and_eq (N % 10 <= previous);
            previous = N % 10;
            N /= 10;
        }

        bool decreasing = true;
        previous = n % 10;
        N = n / 10;
        while ( N > 0 ) {
            decreasing and_eq (N % 10 >= previous);
            previous = N % 10;
            N /= 10;
        }

        if ( not (increasing or decreasing) )
            cnt++;

    } while ( 100*cnt < 99*n );

    cout << n << endl;

    return 0;
}
