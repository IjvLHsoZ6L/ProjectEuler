// 0047.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 2e5;

    int factors[target];
    for ( int i = 1; i < target; i++ )
        factors[i] = 0;
    for ( int i = 2; i < target; i++ )
        if ( factors[i] == 0 )
            for ( int j = 1; i*j < target; j++ )
                factors[i*j]++;

    bool detected = false;
    int answer;
    for ( int i = 1; i + 4 <= target; i++ ) {

        bool consective = true;
        for ( int j = 0; j < 4; j++ )
            consective and_eq (factors[i + j] == 4);

        if ( consective ) {
            detected = true;
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}
