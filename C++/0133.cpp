#include <iostream>

using namespace std;

inline long power(long base, long index, long modulo) {
    long accum = 1;
    while (index > 0) {
        if (index % 2 == 0) {
            index /= 2;
            base = base * base % modulo;
        }
        else {
            index--;
            accum = accum * base % modulo;
        }
    }
    return accum;
}

const int LIMIT = 1E5;

bool prime[LIMIT];

int main() {

    for (int i = 2; i < LIMIT; i++)
        prime[i] = true;
    for (int i = 2; i * i < LIMIT; i++)
        if (prime[i])
            for (int j = i * i; j < LIMIT; j += i)
                prime[j] = false;


    int sum = 0;
    for (int p = 2; p < LIMIT; p++) {

        if (!prime[p])
            continue;

        if (p == 3) {
            sum += p;
            continue;
        }

        int power_of_two = 1;
        while (power_of_two * 2 <= p - 1)
            power_of_two *= 2;

        int power_of_five = 1;
        while (power_of_five * 5 <= p - 1)
            power_of_five *= 5;

        if (power(10, 1L * power_of_two * power_of_five, p) != 1)
            sum += p;
    }

    cout << sum << endl;

    return 0;
}
