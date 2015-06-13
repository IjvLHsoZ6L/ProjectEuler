#include <iostream>

using namespace std;

inline int gcd(int a, int b) {
    int c;
    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

const int LIMIT = 120000;

int radical[LIMIT];

int main() {

    for (int n = 1; n < LIMIT; n++)
        radical[n] = 1;
    for (int n = 1; n < LIMIT; n++)
        if (radical[n] == 1)
            for (int m = n; m < LIMIT; m+= n)
                radical[m] *= n;

    int sum = 0;
    for (int c = 3; c < LIMIT; c++) {
        if (1L * radical[1] * radical[c - 1] * radical[c] < c)
            sum += c;
        if (1L * 2 * 3 * radical[c] < c)
            for (int a = 2, b = c - a; a < b; a++, b--)
                if (1L * radical[a] * radical[b] * radical[c] < c)
                    if (gcd(a, b) == 1)
                        sum += c;
    }

    cout << sum << endl;

    return 0;
}
