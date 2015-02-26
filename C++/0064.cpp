// 064.cpp
#include <iostream>
using namespace std;

int main() {

    int odds = 0;
    for ( int base = 2; base <= 10000; base++ ) {

        int root = 0;
        while ( (root+1)*(root+1) < base )
            root++;

        int c = 1;
        int a = root;
        int b = root;
        int cnt = 0;

        do {
            c = (base - b*b) / c;
            a = (b + root) / c;
            b = root - (b + root) % c;
            cnt++;
        } while ( not(b == root and c == 1) );

        if ( cnt % 2 == 1 )
            odds++;
    }

    cout << odds << endl;

    return 0;
}
