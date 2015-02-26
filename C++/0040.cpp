// 0040.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;
    int spare = 10;

    int digit[target + spare];

    int d = 0;
    int unit = 1;
    int unitindex = 0;
    for ( int n = 0; d <= target; n++ ) {

        if ( n == unit ) {
            unit *= 10;
            unitindex++;
        }

        int N = n;
        for ( int i = 0; i < unitindex; i++ ) {
            digit[d + unitindex - i] = N % 10;
            N /= 10;
        }

        d += unitindex;
    }

    int product = 1;
    for ( int unit = 1; unit <= target; unit *= 10 )
        product *= digit[unit];

    cout << product << endl;

    return 0;
}
