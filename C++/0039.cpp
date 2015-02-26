// 0039.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1000;

    int rats[target + 1]; // number of all right angle triangles with perimeter p
    for ( int p = 0; p <= target; p++ )
        rats[p] = 0;

    for ( int a = 1; 3*a <= target; a++ ) {

        int c = a;
        for ( int b = a; a + b + c <= target; b++ ) {

            while ( c*c < a*a + b*b )
                c++;

            if ( a*a + b*b == c*c and a + b + c <= target )
                rats[a + b + c]++;
        }
    }

    int max = 0, pmax;
    for ( int p = 0; p <= target; p++ ) {
        if ( max < rats[p] ) {
            max = rats[p];
            pmax = p;
        }
    }

    cout << pmax << endl;

    return 0;
}
