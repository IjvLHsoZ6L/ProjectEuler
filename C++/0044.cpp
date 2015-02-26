// 0044.cpp
#include <iostream>
using namespace std;

int main() {

    // P1 + P2 = P3, P1 + P2 + P2 = P4

    bool detected = false;
    int answer;
    int P1 = 1, dP1 = 4, ddP = 3;
    while ( not detected ) {

        long long P2 = 1, dP2 = 4;
        long long P3 = 1, dP3 = 4;
        long long P4 = 1, dP4 = 4;

        bool safe = true;
        while ( safe ) {

            while ( P3 < P1 + P2 ) {
                P3 += dP3;
                dP3 += ddP;
            }

            while ( P4 < P1 + P2 + P2 ) {
                P4 += dP4;
                dP4 += ddP;
            }

            if ( P3 == P1 + P2 and P4 == P1 + P2 + P2 ) {
                safe = false;
                detected = true;
                answer = P1;
            }
            else {
                P2 += dP2;
                dP2 += ddP;

                if ( dP2 > P1 )
                    safe = false;
            }
        }

        P1 += dP1;
        dP1 += ddP;
    }

    cout << answer << endl;

    return 0;
}
