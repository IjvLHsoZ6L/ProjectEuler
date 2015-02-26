// 0137.cpp
#include <iostream>
using namespace std;

int main() {

    long long p = 1, q = 3;
    for ( int cnt = 1; cnt <= 15; cnt++ ) {
        p += q;
        q += p;
        p += q;
        q += p;
    }

    cout << (p - 1) / 5 << endl;

    return 0;
}
