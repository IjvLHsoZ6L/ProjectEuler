// 091.cpp
#include <iostream>
using namespace std;

int main() {

    int cnt = 0;
    for ( int x1 = 0; x1 <= 50; x1++ ) {
        for ( int y1 = 0; y1 <= 50; y1++ ) {
            int a2 = x1*x1 + y1*y1;
            for ( int x2 = 0; x2 <= 50; x2++ ) {
                for ( int y2 = 0; y2 <= 50; y2++ ) {
                    int b2 = x2*x2 + y2*y2;
                    int c2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    if ( x1*y2 - y1*x2 > 0 ) {
                        if ( a2 + b2 == c2 or b2 + c2 == a2 or c2 + a2 == b2) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
