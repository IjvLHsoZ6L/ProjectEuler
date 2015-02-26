// 0119.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 30;

    int base = 100;
    int size = 100;

    int power[base][size], order[base];
    for ( int b = 2; b < base; b++ ) {

        power[b][0] = b * b;
        order[b] = 0;

        while ( power[b][order[b]] > 0 ) {
            power[b][order[b] + 1] = power[b][order[b]] / 10;
            power[b][order[b]] %= 10;
            order[b]++;
        }
    }

    int desiredp[2 * target][size], desiredo[2 * target];
    int cnt = 0;
    for ( int o = 1; cnt < target; o++ ) {
        for ( int b = 2; b < base; b++ ) {
            while ( order[b] == o ) {

                int sum = 0;
                for ( int i = 0; i < o; i++ )
                    sum += power[b][i];

                if ( sum == b ) {

                    cnt++;

                    for ( int i = 0; i < o; i++ )
                        desiredp[cnt][i] = power[b][i];
                    desiredo[cnt] = o;
                }

                for ( int i = 0; i < o; i++ )
                    power[b][i] *= b;

                for ( int i = 0; i < o; i++ ) {
                    power[b][i + 1] += power[b][i] / 10;
                    power[b][i] %= 10;
                }

                while ( power[b][order[b]] > 0 ) {
                    power[b][order[b] + 1] = power[b][order[b]] / 10;
                    power[b][order[b]] %= 10;
                    order[b]++;
                }
            }
        }
    }

    int o = desiredo[target];

    int min = 0;
    while ( desiredo[min] < o )
        min++;

    int max = min;
    while ( max < cnt and desiredo[max + 1] == o )
        max++;

    for ( int k = max; k > min; k-- ) {
        for ( int l = min; l < k; l++ ) {

            int i = o - 1;
            while ( desiredp[l][i] == desiredp[l + 1][i] )
                i--;

            if ( desiredp[l][i] > desiredp[l + 1][i] ) {
                for ( int j = 0; j < o; j++ ) {
                    int temp = desiredp[l][i];
                    desiredp[l][i] = desiredp[l + 1][i];
                    desiredp[l][i + 1] = temp;
                }
            }
        }
    }

    for ( int i = o - 1; i >= 0; i-- )
        cout << desiredp[target][i];
    cout << endl;

    return 0;
}
