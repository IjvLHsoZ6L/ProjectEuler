// 0122.cpp
#include <iostream>
using namespace std;

const int target = 200;
const int size = 15;

int minimum[target + 1];

void format() {

    for ( int k = 1; k <= target; k++ )
        minimum[k] = k - 1;

    return;
}

int made[size + 1];

void sub(int i) {

    if ( i <= minimum[made[i]] ) {

        minimum[made[i]] = i;

        for ( int j = 0; j <= i and made[i] + made[j] <= target; j++ ) {

            made[i + 1] = made[i] + made[j];

            sub(i + 1);
        }
    }

    return;
}

int main() {

    format();

    made[0] = 1;

    sub(0);

    int sum = 0;
    for ( int k = 1; k <= target; k++ )
        sum += minimum[k];

    cout << sum << endl;

    return 0;
}
