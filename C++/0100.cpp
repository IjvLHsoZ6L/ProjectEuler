// 100.cpp
#include <iostream>
using namespace std;

int main() {

    long long target = 1e12;

    long long a = 1, b = 1;
    bool less = true; // 2 a^2 - b^2 = 1
    do {
        b = 2*a + b;
        a = b - a;
        less = not less;
    } while ( (less ? 2*a*(a + b) : b*(2*a + b)) <= target );

    cout << (less ? a*(2*a + b) : b*(a + b)) << endl;

    return 0;
}
