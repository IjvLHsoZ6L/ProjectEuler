// 0005.cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while ( b > 0 ) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {

    int multiple = 1;
    for ( int k = 1; k <= 20; k++ )
        multiple = lcm(multiple, k);

    cout << multiple << endl;

    return 0;
}
