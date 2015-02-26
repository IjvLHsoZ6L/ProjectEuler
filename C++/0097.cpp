// 097.cpp
#include <iostream>
using namespace std;

int main() {

    long long modulo = 1e10;
    int index = 7830457;

    long long power = 28433;
    for ( int cnt = 0; cnt < index; cnt++ )
        power = power * 2 % modulo;

    cout << power + 1 << endl;

    return 0;
}
