// 0020.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 100;
    int size = 10000;

    int digit[size];
    digit[0] = 1;
    for ( int i = 1; i < size; i++ )
        digit[i] = 0;

    for ( int k = 2; k <= target; k++ ) {

        for ( int i = 0; i < size; i++ )
            digit[i] *= k;

        for ( int i = 0; i+1 < size; i++ ) {
            digit[i+1] += digit[i] / 10;
            digit[i] %= 10;
        }
    }

    int sum = 0;
    for ( int i = 0; i < size; i++ )
        sum += digit[i];

    cout << sum << endl;
}
