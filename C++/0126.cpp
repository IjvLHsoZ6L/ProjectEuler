// 0126.cpp
#include <iostream>
using namespace std;

int layer(int l, int a, int b, int c) {
    return 2 * (a * b + a * c + b * c) + 4 * (a + b + c) * (l - 1) + 8 * (l - 1) * (l - 2) / 2;
}

int main() {

    int target = 20000;

    int C[target];
    for ( int n = 0; n < target; n++ )
        C[n] = 0;

    for ( int a = 1; layer(1, a, a, a) < target; a++ )
        for ( int b = a; layer(1, a, b, b) < target; b++ )
            for ( int c = b; layer(1, a, b, c) < target; c++ )
                for ( int l = 1; layer(l, a, b, c) < target; l++ )
                    C[layer(l, a, b, c)]++;

    int n = 0;
    while ( C[n] != 1000 )
        n++;

    cout << n << endl;

    return 0;
}
