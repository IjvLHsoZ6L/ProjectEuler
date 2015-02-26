// 056.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 201;

    int max = 0;
    for ( int a = 1; a < 100; a++ ) {

        int pow[size];
        pow[0] = 1;
        for ( int i = 1; i < size; i++ )
            pow[i] = 0;

        for ( int b = 1; b < 100; b++ ) {
            for ( int i = 0; i < size; i++ )
                pow[i] *= a;
            for ( int i = 0; i+1 < size; i++ ) {
                pow[i+1] += pow[i]/10;
                pow[i] %= 10;
            }
            if ( pow[size-1] > 0 )
                throw;

            int sum = 0;
            for ( int i = 0; i < size; i++ )
                sum += pow[i];

            if ( max < sum )
                max = sum;
        }
    }

    cout << max << endl;


    return 0;
}
