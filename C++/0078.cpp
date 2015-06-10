#include <iostream>

using namespace std;

const int SIZE = 1 << 16;

const int MODULO = 1E6;

int p[SIZE];

int main() {

    p[0] = 1;
    for (int n = 1; n < SIZE; n++)
        p[n] = 0;

    for (int k = 1; k < SIZE; k++) {
        for (int n = k; n < SIZE; n++) {
            p[n] += p[n - k];
            p[n] %= MODULO;
        }
        if (p[k] == 0) {
            cout << k << endl;
            return 0;
        }
    }

    return 1;
}
