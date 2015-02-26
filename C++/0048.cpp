// 0048.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1000;

    int sum[10 + 1];
    for ( int i = 0; i < 10; i++ )
        sum[i] = 0;

    for ( int n = 1; n <= target; n++ ) {

        int power[10 + 1];
        power[0] = 1;
        for ( int i = 1; i < 10; i++ )
            power[i] = 0;

        for ( int cnt = 0; cnt < n; cnt++ ) {

            for ( int i = 0; i < 10; i++ )
                power[i] *= n;

            for ( int i = 0; i < 10; i++ ) {
                power[i + 1] += power[i] / 10;
                power[i] %= 10;
            }
        }

        for ( int i = 0; i < 10; i++ )
            sum[i] += power[i];

        for ( int i = 0; i < 10; i++ ) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }

    for ( int i = 1; i <= 10; i++ )
        cout << sum[10 - i];
    cout << endl;

    return 0;
}
