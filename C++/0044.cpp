#include <iostream>
#include <map>

using namespace std;

inline int pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

const int LIMIT = 5E3;

map<int, int> sum_map[LIMIT];

int main() {

    int i, j, k, sum;
    map<int, int>::iterator it;

    for (i = 1; i < LIMIT; i++) {
        k = i;
        for (j = 1; j < LIMIT; j++) {
            sum = pentagonal(i) + pentagonal(j);
            while (pentagonal(k) < sum)
                k++;
            if (pentagonal(k) == sum)
                sum_map[i].insert(pair<int, int>(j, k));
        }
    }

    for (i = 1; i < LIMIT; i++) {
        for (it = sum_map[i].begin(); it != sum_map[i].end(); it++) {
            j = it->first;
            k = it->second;
            if (sum_map[j].find(k) != sum_map[j].end()) {
                cout << pentagonal(i) << endl;
                return 0;
            }
        }
    }

    return 1;
}
