// 0111.cpp
#include <iostream>
using namespace std;

const int root = 1e5;
bool prime[root];
int p[root], primes;

void makeprime() {

    prime[0] = prime[1] = false;
    for ( int i = 2; i < root; i++ )
        prime[i] = true;

    for ( int i = 2; i*i < root; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < root; j++ )
                prime[i*j] = false;

    primes = 0;
    for ( int i = 0; i < root; i++ )
        if ( prime[i] )
            p[primes++] = i;

    return;
}

int choice[10];

long long sum;

void sub(int d, int m, int k) {

    if ( k == m ) {

        int digit[10];
        for ( int i = 0; i < 10; i++ )
            digit[i] = d;

        long long target = 1;
        for ( int i = 0; i < m; i++ )
            target *= 10;

        for ( long long n = 0; n < target; n++ ) {

            int other[m];
            for ( long long N = n, i = 0; i < m; i++, N /= 10 )
                digit[choice[i]] = N % 10;

            if ( digit[0] > 0 ) {

                long long N = 0;
                for ( int i = 0; i < 10; i++ )
                    N = N * 10 + digit[i];

                bool divisible = false;
                for ( int i = 0; i < primes and not divisible; i++ )
                    if ( N % p[i] == 0 )
                        divisible = true;

                if ( not divisible )
                    sum += N;
            }
        }

        return;
    }

    int first = (k == 0 ? 0 : choice[k - 1] + 1);

    for ( int l = first; l < 10; l++ ) {
        choice[k] = l;
        sub(d, m, k + 1);
    }

    return;
}

int main() {

    makeprime();

    long long answer = 0;

    for ( int d = 0; d <= 9; d++ ) {

        bool detected = false;

        for ( int m = 1; not detected; m++ ) {

            sum = 0;
            sub(d, m, 0);

            if ( sum > 0 ) {
                detected = true;
                answer += sum;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
