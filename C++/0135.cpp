#include <iostream>

using namespace std;

const int LIMIT = 1E6;

int n_solutions[LIMIT];

int main() {

    for (int n = 1; n < LIMIT; n++)
        n_solutions[n] = 0;

    int n;
    for (int m = 1; m < LIMIT; m++) {
        for (int d = m / 4 + 1; d < m; d++) {
            n = m * (4 * d - m);
            if (n >= LIMIT)
                break;
            n_solutions[n]++;
        }
    }

    int count = 0;
    for (int n = 1; n < LIMIT; n++)
        if (n_solutions[n] == 10)
            count++;

    cout << count << endl;

    return 0;
}
