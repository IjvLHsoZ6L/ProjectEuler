// 0129.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    bool exceed = false;
    for ( int n = target; not exceed; n++ ) {
        if (n % 2 > 0 and n % 5 > 0 ) {

            int k = 1;
            int R = 1;
            while ( R % n > 0 ) {
                R %= n;
                R = R * 10 + 1;
                k++;
            }

            if ( k > target ) {
                exceed = true;
                cout << n << endl;
            }
        }
    }

    return 0;
}
