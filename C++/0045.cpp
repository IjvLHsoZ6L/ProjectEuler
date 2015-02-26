// 0045.cpp
#include <iostream>
using namespace std;

int main() {

    int first = 40755;

    long long T = 1, P = 1, H = 1;
    int dT = 2, dP = 4, dH = 5;
    int ddT = 1, ddP = 3, ddH = 4;

    bool detected = false;
    while ( not detected ) {

        T += dT;
        dT += ddT;

        while ( P < T ) {
            P += dP;
            dP += ddP;
        }

        while ( H < T ) {
            H += dH;
            dH += ddH;
        }

        if ( T == P and T == H and T != first )
            detected = true;
    }

    cout << T << endl;

    return 0;
}
