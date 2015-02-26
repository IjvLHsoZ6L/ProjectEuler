// 0135.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 1e6;

    int answer = 0;
    for ( int n = 1; n < target; n++ ) {

        int cnt = 0;
        for ( int d = 1; cnt <= 10 and d*d < 3*n; d++ )
            if ( n % d == 0 and (d + n / d) % 4 == 0 )
                cnt++;

        if ( cnt == 10 )
            answer++;
    }

    cout << answer << endl;

    return 0;
}
