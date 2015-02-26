// 0125.cpp
#include <iostream>
using namespace std;

int main() {

    const int target = 1e8;

    static int desired[target];
    for ( int n = 0; n < target; n++ )
        desired[n] = false;

    for ( int start = 1; 2 * start * start < target; start++ ) {

        int sum = start * start;
        for ( int end = start + 1; sum + end * end < target; end++ ) {

            sum += end * end;

            int reverse = 0;
            for ( int N = sum; N > 0; N /= 10 )
                reverse = reverse * 10 + N % 10;

            if ( reverse == sum )
                desired[sum] = true;
        }
    }

    long long sum = 0;
    for ( int n = 0; n < target; n++ )
        if ( desired[n] )
            sum += n;

    cout << sum << endl;

    return 0;
}
