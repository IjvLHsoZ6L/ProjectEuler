#include <iostream>

using namespace std;

const int LIMIT = 5E7;

int n_solutions[LIMIT];

int main() {

    for (int n = 1; n < LIMIT; n++)
        n_solutions[n] = 0;

    for (int m = 1; m < LIMIT; m++)
        for (int d = m / 4 + 1, n = m * (4 * d - m); n < LIMIT and d < m; d++, n += 4 * m)
            n_solutions[n]++;

    int count = 0;
    for (int n = 1; n < LIMIT; n++)
        if (n_solutions[n] == 1)
            count++;

    cout << count << endl;

    return 0;
}
