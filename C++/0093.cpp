// 093.cpp
#include <iostream>
using namespace std;

class rat {

    private:

        int n;
        int d;

    public:

        rat() {
            n = 0;
            d = 1;
        }

        rat(int a) {
            n = a;
            d = 1;
        }

        rat(int numer, int denom) {
            n = numer;
            d = denom;
        }

        int numer() {
            return n;
        }

        int denom() {
            return d;
        }

        bool integer() {
            return (not d == 0) and n % d == 0;
        }

        int toint() {
            return n / d;
        }

        void operator=(int a) {
            n = a;
            d = 1;
        }

        void operator=(rat a) {
            n = a.n;
            d = a.d;
        }

        rat operator+(rat a) {
            rat r(n * a.d + d * a.n, d * a.d);
            return r;
        }

        rat operator-(rat a) {
            rat r(n * a.d - d * a.n, d * a.d);
            return r;
        }

        rat operator*(rat a) {
            rat r(n * a.n, d * a.d);
            return r;
        }

        rat operator/(rat a) {
            rat r(n * a.d, d * a.n);
            return r;
        }
};

rat rational(int a) {
    rat r(a);
    return r;
}

rat op(rat a, rat b, int o) {
    switch ( o ) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return b - a;
        case 3: return a * b;
        case 4: return a / b;
        case 5: return b / a;
    }
}

int main() {

    int MAX = 1e4;
    int longest = 0;
    int alongest[4];

    int a[4];

    for ( a[0] = 1; a[0] <= 9; a[0]++ ) {
        for ( a[1] = a[0]+1; a[1] <= 9; a[1]++ ) {
            for ( a[2] = a[1]+1; a[2] <= 9; a[2]++ ) {
                for ( a[3] = a[2]+1; a[3] <= 9; a[3]++ ) {

                    bool exp[MAX];
                    for ( int x = 1; x < MAX; x++ )
                        exp[x] = false;

                    for ( int o1 = 0; o1 < 6; o1++ ) {
                        for ( int o2 = 0; o2 < 6; o2++ ) {
                            for ( int o3 = 0; o3 < 6; o3++ ) {

                                rat r;

                                r = op(op(a[0], a[1], o1), op(a[2], a[3], o2), o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(a[0], a[2], o1), op(a[1], a[3], o2), o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(a[0], a[3], o1), op(a[1], a[2], o2), o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[1], o1), a[2], o2), a[3], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[1], o1), a[3], o2), a[2], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[2], o1), a[1], o2), a[3], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[2], o1), a[3], o2), a[1], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[3], o1), a[1], o2), a[2], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[0], a[3], o1), a[2], o2), a[1], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[1], a[2], o1), a[0], o2), a[3], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[1], a[2], o1), a[3], o2), a[0], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[1], a[3], o1), a[0], o2), a[2], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[1], a[3], o1), a[2], o2), a[0], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[2], a[3], o1), a[1], o2), a[0], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;

                                r = op(op(op(a[2], a[3], o1), a[0], o2), a[1], o3);
                                if ( r.integer() and r.toint() > 0 )
                                    exp[r.toint()] = true;
                            }
                        }
                    }

                    int l = 0;
                    while ( exp[l + 1] )
                        l++;

                    if ( longest < l ) {
                        longest = l;
                        for ( int i = 0; i < 4; i++ )
                            alongest[i] = a[i];
                    }
                }
            }
        }
    }

    for ( int i = 0; i < 4; i++ )
        cout << alongest[i];
    cout << endl;

    return 0;
}
