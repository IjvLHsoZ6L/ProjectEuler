// 058.cpp
#include <iostream>
using namespace std;

const int LENGTH = 30000;
const int PRIME = LENGTH*LENGTH;
bool prime[PRIME];

int main() {

    prime[0] = prime[1] = false;
    for ( int i = 2; i < PRIME; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < PRIME; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < PRIME; j++ )
                prime[i*j] = false;

    bool detected = false;
    int length = 1;
    int diagonals = 1;
    int primes = 0;
    do {
        length += 2;
        diagonals += 4;
        for ( int i = 0; i < 4; i++ )
            if ( prime[length*length - i*(length-1)] )
                primes++;
    } while ( 10*primes >= diagonals );

    cout << length << endl;

    return 0;
}
