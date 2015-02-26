// 0021.cpp
#include <iostream>
using namespace std;

int d(int n) {

    int N = n;
    int sumofdivisors = 1;
    for ( int d = 2; N > 1; d++ ) {
        if ( N % d == 0 ) {

            int sumofpower = 1;
            while ( N % d == 0 ) {
                sumofpower *= d;
                sumofpower++;
                N /= d;
            }

            sumofdivisors *= sumofpower;
        }
    }

    return sumofdivisors - n;
}

int main() {

    int target = 10000;

    int sum = 0;
    for ( int n = 2; n < target; n++ )
        if ( d(n) != n and d(d(n)) == n )
            sum += n;

    cout << sum << endl;

    return 0;
}
