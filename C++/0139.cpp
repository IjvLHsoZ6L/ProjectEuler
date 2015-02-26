// 0139.cpp
#include <iostream>
using namespace std;

int main() {

    long long target = 1e8;
    long long cnt = 0;
    long long d = 5, n = 7;

    while ( d + n < target ) {

        cnt += target / (d + n);

        int dd = 3*d + 2*n;
        int nn = 4*d + 3*n;
        d = dd;
        n = nn;
    }

    cout << cnt << endl;

    return 0;
}
