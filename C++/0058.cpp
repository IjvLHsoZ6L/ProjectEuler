#include <iostream>

using namespace std;

inline bool is_prime(long n) {
    for (long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
}

int main() {

    long current = 1;
    int size = 1;
    int total_count = 1;
    int prime_count = 0;
    while (true) {

        size += 2;
        total_count += 4;

        for (int i = 0; i < 4; i++) {
            current += size - 1;
            if (is_prime(current))
                prime_count++;
        }

        if (10 * prime_count < total_count)
            break;
    }

    cout << size << endl;

    return 0;
}
