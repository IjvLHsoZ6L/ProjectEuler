#include <iostream>

using namespace std;

const int PRIME = 1E6;

bool prime[PRIME];

int main() {

    for (int i = 2; i < PRIME; i++)
        prime[i] = true;
    for (int i = 2; i * i < PRIME; i++)
        if (prime[i])
            for (int j = i * i; j < PRIME; j += i)
                prime[j] = false;

    int n = 1;
    int p = 2;
    while (true) {
        if (2L * n * p > 1E10L) {
            cout << n << endl;
            return 0;
        }
        for (int i = 0; i < 2; i++) {
            n++;
            p++;
            while (!prime[p])
                p++;
        }
    }

    return 1;
}
