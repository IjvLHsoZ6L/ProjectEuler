// 0138.cpp
#include <iostream>
using namespace std;

int main() {

    int cnt = 0;
    long long sum = 0;
    long long denom = 4, numer = 1;

    // denom : numer ~ 1 : sqrt 5 - 2
    // denom : 2 * denom + numer ~ 1 : sqrt 5

    while ( cnt < 12 ) {

        long long temp = denom;
        denom = 4 * denom + numer;
        numer = temp;

        if ( (2 * denom + numer) % 5 == 2 or (2 * denom + numer) % 5 == 3 ) {
            cnt++;
            sum += denom;
        }
    }

    cout << sum << endl;

    return 0;
}
