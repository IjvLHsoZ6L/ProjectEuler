// 094.cpp
#include <iostream>
using namespace std;

int main() {

    int MAX = 1e9;
    long long sum = 0;
    long long h;

    h = 0;
    for ( long long l = 1; 6*l + 2 <= MAX; l++ ) {
        while ( h*h < 3*l*l + 4*l + 1 )
            h++;
        if ( h*h == 3*l*l + 4*l + 1 )
            sum += 6*l + 2;
    }

    h = 0;
    for ( long long l = 2; 6*l - 2 <= MAX; l++ ) {
        while ( h*h < 3*l*l - 4*l + 1 )
            h++;
        if ( h*h == 3*l*l - 4*l + 1 )
            sum += 6*l - 2;
    }

    cout << sum << endl;

    return 0;
}
