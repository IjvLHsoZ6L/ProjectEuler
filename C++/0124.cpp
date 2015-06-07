#include <iostream>
#include <utility>
#include <queue>

using namespace std;

const int MAX = 100000;

int radical[MAX + 1];
int E[MAX + 1];

inline bool leq(int i, int j) {
    return radical[i] < radical[j] or (radical[i] == radical[j] and E[i] <= E[j]);
}

inline void exchange(int i, int j) {
    swap(radical[i], radical[j]);
    swap(E[i], E[j]);
}

inline void sort(int l, int r) {
    if (r <= l)
        return;
    int i = l;
    int j = r;
    int p = l;
    while (true) {
        while (i <= r and leq(i, p))
            i++;
        while (j >= l and leq(p, j))
            j--;
        if (j < i)
            break;
        exchange(i, j);
    }
    if (j == r) {
        exchange(l, r);
        sort(l, r - 1);
    }
    else {
        sort(l, j);
        sort(i, r);
    }
}

int main() {

    for (int n = 1; n <= MAX; n++)
        radical[n] = 1;
    for (int n = 2; n <= MAX; n++)
        if (radical[n] == 1)
            for (int m = n; m <= MAX; m += n)
                radical[m] *= n;

    for (int n = 1; n <= MAX; n++)
        E[n] = n;

    sort(1, MAX);

    cout << E[10000] << endl;

    return 0;
}
