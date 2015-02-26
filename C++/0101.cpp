// 0101.cpp
#include <iostream>
using namespace std;

int main() {

    long long u[10 + 1];
    for ( int n = 1; n <= 10; n++ ) {

        u[n] = 1;

        long long power = 1;
        for ( int i = 1; i <= 10; i++ ) {
            power *= -n;
            u[n] += power;
        }
    }

    long long sum = 0;

    long long approx[11 + 1];
    for ( int n = 1; n <= 11; n++ )
        approx[n] = 0;

    for ( int k = 1; k <= 10; k++ ) {

        int a = u[k] - approx[k];
        for ( int i = 1; i < k; i++ )
            a /= k - i;

        for ( int n = k; n <= 11; n++ ) {

            long long product = 1;
            for ( int i = 1; i < k; i++ )
                product *= n - i;

            approx[n] += product * a;
        }

        sum += approx[k + 1];
    }

    cout << sum << endl;

    return 0;
}
