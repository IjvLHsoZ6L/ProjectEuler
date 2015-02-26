// 0103.cpp
#include <iostream>
using namespace std;

const int n = 7;
const int size = 300;

int a[n + 1], b[n + 1];

bool appear[n + 1][size];

bool check(int k) {

    b[k] = b[k - 1] + a[k];

    for ( int i = 0; i + a[k] <= b[k - 1]; i++ )
        if ( appear[k - 1][i] and appear[k - 1][i + a[k]] )
            return false;

    for ( int i = 0; i <= b[k]; i++ )
        appear[k][i] = false;

    for ( int i = 0; i <= b[k - 1]; i++ )
        if ( appear[k - 1][i] )
            appear[k][i] = appear[k][i + a[k]] = true;

    return true;
}

bool sub(int sum, int k) {

    if ( k == 0 ) {

        a[0] = b[0] = 0;
        appear[0][0] = true;

        return sub(sum, 1);
    }
    else if ( k == n ) {

        a[n] = sum - b[n - 1];

        for ( int l = 1; l + l + 1 <= n; l++ )
            if ( a[n] > b[l + 1] + b[n - l] - b[n - 1] - 1 )
                return false;

        return check(n);
    }
    else {

        int max = (sum - b[k - 1] - (n - k) * (n - k + 1) / 2) / (n - k + 1);
        for ( int l = 1; l + l + 1 <= k; l++ )
            if ( max > b[l + 1] + b[k - l] - b[k - 1] - 1 )
                max = b[l + 1] + b[k - l] - b[k - 1] - 1;

        for ( a[k] = a[k - 1] + 1; a[k] <= max; a[k]++ )
            if ( check(k) )
                if ( sub(sum, k + 1) )
                    return true;

        return false;
    }
}

int main() {

    bool detected = false;
    for ( int sum = n * (n + 1) / 2; not detected; sum++ )
        detected = sub(sum, 0);

    for ( int k = 1; k <= n; k++ )
        cout << a[k];
    cout << endl;

    return 0;
}
