#include <iostream>
#include <list>
#include <set>

using namespace std;

const int MAX = 120000;

set<int> pairs[MAX / 2 + 1];

set<int> sums;

const int SIZE = 3 * MAX + 1;

list<int> divisors[SIZE];

inline long min_square(long n) {
    long m = 1;
    for (int d : divisors[n]) {
        int count = 0;
        while (n % d == 0) {
            n /= d;
            count++;
        }
        while (count > 0) {
            m *= d;
            count -= 2;
        }
    }
    return m;
}

int sum;

int main() {

    for (int i = 2; i < SIZE; i++)
        if (divisors[i].empty())
            for (int j = i; j < SIZE; j += i)
                divisors[j].push_back(i);

    long p, q;
    for (long s = 1; s <= MAX; s++) {
        long t0 = min_square(3 * s) / 3;
        long t = t0;
        while (t <= s)
            t += t0;
        while (true) {
            q = 2 * t - s;
            p = (3 * t * t - 4 * t * s + s * s) / s;
            if (p > q or p + q > MAX)
                break;
            pairs[p].insert(q);
            t += t0;
        }
    }

    for (int p = 1; p + p + p <= MAX; p++)
        for (int q : pairs[p])
            for (int r : pairs[p])
                if (q < r and p + q + r <= MAX and pairs[q].count(r) > 0)
                    sums.insert(p + q + r);

    sum = 0;
    for (int s : sums)
        sum += s;

    cout << sum << endl;

    return 0;
}
