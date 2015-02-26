// 0118.cpp
#include <iostream>
using namespace std;

const int target = 1e8;

bool prime[target];

void makeprime() {

    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;

    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    return;
}

int align[9], cnt;

void sub(int i, int previous) {

    if ( i == 9 ) {

        cnt++;

        return;
    }

    for ( int p = 0; i < 9; i++ ) {

        p = p * 10 + align[i];

        if ( p > previous and p < target and prime[p] )
            sub(i + 1, p);
    }

    return;
}



int main() {

    makeprime();

    int factorial = 1;
    for ( int i = 1; i <= 9; i++ )
        factorial *= i;

    cnt = 0;
    for ( int n = 0; n < factorial; n++ ) {

        for ( int N = n, i = 1; i <= 9; N /= i, i++ )
            align[9 - i] = N % i;

        int remain[9 + 1];
        for ( int d = 1; d <= 9; d++ )
            remain[d] = true;

        for ( int i = 0; i < 9; i++ ) {

            int d = 0;
            for ( int cnt = 0; cnt <= align[i]; cnt++ ) {

                d++;

                while ( not remain[d] )
                    d++;
            }

            align[i] = d;
            remain[d] = false;
        }

        sub(0, 0);
    }

    cout << cnt << endl;

    return 0;
}
