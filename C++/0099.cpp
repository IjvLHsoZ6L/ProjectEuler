// 099.cpp
#include <iostream>
using namespace std;

const long long modulo = 1e8;

class big {
    public:

        long long index;
        long long base;

        void carry() {
            while ( not (base < modulo) ) {
                index++;
                base /= 10;
            }
        }

        big() {
            index = 0;
            base = 0;
        }

        big(const int& n) {
            index = 0;
            base = n;
            carry();
        }

        big(const big& a) {
            index = a.index;
            base = a.base;
        }

        big operator=(const big& a) {
            index = a.index;
            base = a.base;
        }

        big operator*(int n) {
            big prod = *this;
            prod.base *= n;
            prod.carry();
            return prod;
        }

        big operator*(big a) {
            big prod;
            prod.index = index + a.index;
            prod.base = base * a.base;
            prod.carry();
            return prod;
        }

        bool operator<(big a) {
            if ( index == a.index )
                return base < a.base;
            else
                return index < a.index;
        }
};

int main() {

    int SIZE = 1000;

    int base[SIZE];
    int index[SIZE];
    for ( int i = 0; i < SIZE; i++ ) {
        cin >> base[i];
        cin >> index[i];
    }

    big max = 0;
    int imax = 0;
    for ( int i = 0; i < SIZE; i++ ) {

        int pow2[100];
        pow2[0] = 1;
        big sqpow[100];
        sqpow[0] = base[i];

        int k = 0;
        while ( 2*pow2[k] <= index[i] ) {
            pow2[k+1] = 2*pow2[k];
            sqpow[k+1] = sqpow[k]*sqpow[k];
            k++;
        }

        big power = 1;
        int rest = index[i];
        while ( rest > 0 ) {

            while ( pow2[k] <= rest ) {
                power = power * sqpow[k];
                rest -= pow2[k];
            }

            k--;
        }

        if ( max < power ) {
            max = power;
            imax = i;
        }
    }

    cout << imax + 1 << endl;

    return 0;
}
