// 092.cpp
#include <iostream>
using namespace std;

// sum of the square of the digits
int ssd(int n) {
    int sum = 0;
    while ( n > 0 ) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

int main() {

    int max = 9*9*7;
    int target = 1e7;

    int arrive[max+1];
    for ( int n = 1; n <= max; n++ )
        arrive[n] = 0;
    arrive[1] = 1;
    arrive[89] = 89;

    for ( int n = 1; n <= max; n++ ) {
        int m = n;
        while ( arrive[m] == 0 )
            m = ssd(m);
        int end = arrive[m];
        m = n;
        while ( arrive[m] == 0 ) {
            arrive[m] = end;
            m = ssd(m);
        }
    }

    int cnt = 0;
    for ( int n = 1; n < target; n++ )
        if ( arrive[ssd(n)] == 89 )
            cnt++;

    cout << cnt << endl;

    return 0;
}
