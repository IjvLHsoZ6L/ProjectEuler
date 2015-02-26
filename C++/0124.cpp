// 0124.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e5;

    int radical[target + 1];

    for ( int n = 1; n <= target; n++ )
        radical[n] = 1;

    for ( int n = 2; n <= target; n++ )
        if ( radical[n] == 1 )
            for ( int m = 1; n*m <= target; m++ )
                radical[n*m] *= n;

    int E[target + 1];
    for ( int n = 1; n <= target; n++ )
        E[n] = n;

    for ( int n = target; n > 1; n-- ) {
        for ( int m = 1; m < n; m++ ) {
            if ( radical[m] > radical[m + 1] ) {
                int temp = radical[m];
                radical[m] = radical[m + 1];
                radical[m + 1] = temp;
                temp = E[m];
                E[m] = E[m + 1];
                E[m + 1] = temp;
            }
        }
    }

    cout << E[10000] << endl;

    return 0;
}
