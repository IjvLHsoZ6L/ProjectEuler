// 0016.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1000;

    int value[size];
    value[0] = 1;
    for ( int i = 1; i < size; i++ )
        value[i] = 0;

    for ( int i = 0; i < 1000; i++ ) {

        for ( int j = 0; j < size; j++ )
            value[j] *= 2;

        for ( int j = 0; j+1 < size; j++ ) {
            value[j+1] += value[j] / 10;
            value[j] %= 10;
        }
    }

    int sum = 0;
    for ( int i = 0; i < size; i++ )
        sum += value[i];

    cout << sum << endl;

    return 0;
}
