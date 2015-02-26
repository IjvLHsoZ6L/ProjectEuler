// 0136.cpp
#include <iostream>
using namespace std;

int main() {

    const int target = 5e7;

    static int solutions[target];
    for ( int n = 1; n < target; n++ )
        solutions[n] = 0;

    for ( int a = 1; a < target; a++ )
        for ( int d = 1; d < 3 * a and a * d < target; d++ )
            if ( (a + d) % 4 == 0 )
                solutions[a * d]++;

    int cnt = 0;
    for ( int n = 1; n < target; n++ )
        if ( solutions[n] == 1 )
            cnt++;

    cout << cnt << endl;

    return 0;
}
