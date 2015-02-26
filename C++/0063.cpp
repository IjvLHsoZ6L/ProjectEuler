// 063.cpp
#include <iostream>
using namespace std;

int main() {

    int dmax = 100;

    int cnt = 0;
    for ( int b = 1; b < 10; b++ ) {

        int power[dmax];
        power[0] = 0;
        power[1] = b;
        for ( int d = 2; d < dmax; d++ )
            power[d] = 0;

        for ( int i = 1; power[i] > 0; i++ ) {
            cnt++;
            for ( int d = 1; d < dmax; d++ ) {
                power[d] *= b;
                power[d] += power[d-1] / 10;
                power[d-1] %= 10;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
