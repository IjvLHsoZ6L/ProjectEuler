// 0120.cpp
#include <iostream>
using namespace std;

int main() {

    int sum = 0;
    for ( int a = 3; a <= 1000; a++ ) {

        /*
        int rmax = 0, term1 = 1, term2 = 1;
        for ( int n = 0, term1 = 1, term2 = 1; n < a * a; n++, term1 = term1 * (a - 1) % (a * a), term2 = term2 * (a + 1) % (a * a) )
            if ( (term1 + term2) % (a * a) > rmax )
                rmax = (term1 + term2) % (a * a);

        cout << a << "\t" << rmax << "\t" << a * a << "\t" << a * a - rmax << endl;

        sum += rmax;
        */

        if ( a % 2 == 0 )
            sum += a * (a - 2);
        else
            sum += a * (a - 1);
    }

    cout << sum << endl;

    return 0;
}
