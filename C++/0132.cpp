#include <iostream>

using namespace std;

inline int power(int base, int index, int modulo) {
    int accum = 1;
    while (index > 0) {
        if (index % 2 == 0) {
            base = 1L * base * base % modulo;
            index /= 2;
        }
        else {
            accum = 1L * accum * base % modulo;
            index--;
        }
    }
    return accum;
}

const int N = 1e9;

const int PRIME = 2e5;

bool prime[PRIME];

int main() {

    for (int n = 2; n < PRIME; n++)
        prime[n] = true;
    for (int n = 2; n * n < PRIME; n++)
        if (prime[n])
            for (int m = n * n; m < PRIME; m += n)
                prime[m] = false;

    int sum = 0;
    for (int p = 7, count = 0; count < 40; p++) {
        if (!prime[p])
            continue;
        if (power(10, N, p) == 1) {
            count++;
            sum += p;
        }
    }

    cout << sum << endl;

    return 0;
}
