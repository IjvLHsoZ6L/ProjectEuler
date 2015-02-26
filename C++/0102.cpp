// 0102.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1000;

    int cnt = 0;
    for ( int i = 0; i < size; i++ ) {

        int x[3], y[3];
        for ( int i = 0; i < 3; i++ ) {
            cin >> x[i];
            cin >> y[i];
        }

        if ( x[0]*y[1] + x[1]*y[2] + x[2]*y[0] - y[0]*x[1] - y[1]*x[2] - y[2]*x[0] > 0 ) {

            bool inside = true;
            inside and_eq x[0]*y[1] - y[0]*x[1] > 0;
            inside and_eq x[1]*y[2] - y[1]*x[2] > 0;
            inside and_eq x[2]*y[0] - y[2]*x[0] > 0;

            if ( inside )
                cnt++;
        }
        else {

            bool inside = true;
            inside and_eq x[0]*y[1] - y[0]*x[1] < 0;
            inside and_eq x[1]*y[2] - y[1]*x[2] < 0;
            inside and_eq x[2]*y[0] - y[2]*x[0] < 0;

            if ( inside )
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
