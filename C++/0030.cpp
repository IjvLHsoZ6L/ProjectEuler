// 0030.cpp
#include <iostream>
using namespace std;

int fifthpower(int n) {
    return n*n*n*n*n;
}

int main() {

    int sum = 0;
    for ( int n = 2; n < 1000000; n++ ) {
        int N = n;
        int sumoffifthpower = 0;
        while ( N > 0 ) {
            sumoffifthpower += fifthpower(N % 10);
            N /= 10;
        }
        if ( n == sumoffifthpower )
            sum += n;
    }

    cout << sum << endl;

    return 0;
}
