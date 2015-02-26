// 096.cpp
#include <iostream>
using namespace std;

/* v    i   j   k
 * 0    row col num
 * 1    num row col
 * 2    num col row
 * 3    num BOX box
 */

int i_(int v, int p) {
    switch ( v ) {
        case 0: return p/9/9;
        case 1: return p%9;
        case 2: return p%9;
        case 3: return p%9;
    }
}

int j_(int v, int p) {
    switch ( v ) {
        case 0: return p/9%9;
        case 1: return p/9/9;
        case 2: return p/9%9;
        case 3: return p/9/9/3*3 + p/9%9/3;
    }
}

int k_(int v, int p) {
    switch ( v ) {
        case 0: return p%9;
        case 1: return p/9%9;
        case 2: return p/9/9;
        case 3: return p/9/9%3*3 + p/9%9%3;
    }
}

int p_(int v, int i, int j, int k) {
    switch ( v ) {
        case 0: return i*9*9 + j*9 + k;
        case 1: return j*9*9 + k*9 + i;
        case 2: return k*9*9 + j*9 + i;
        case 3: return (j/3*3 + k/3)*9*9 + (j%3*3 + k%3)*9 + i;
    }
}

class sudoku {

    public:

        bool possible[9*9*9];
        bool defined[4][9][9];
        int value[4][9][9];

        sudoku() {
            for ( int p = 0; p < 9*9*9; p++ )
                possible[p] = true;
            for ( int v = 0; v < 4; v++ ) {
                for ( int i = 0; i < 9; i++ ) {
                    for ( int j = 0; j < 9; j++ ) {
                        defined[v][i][j] = false;
                        value[v][i][j] = -1;
                    }
                }
            }
        }

        void fill(int p) {
            for ( int v = 0; v < 4; v++ ) {
                int i0 = i_(v, p);
                int j0 = j_(v, p);
                int k0 = k_(v, p);
                defined[v][i0][j0] = true;
                value[v][i0][j0] = k0;
                for ( int k = 0; k < 9; k++ )
                    possible[p_(v, i0, j0, k)] = false;
            }
        }

        void load() {
            for ( int i = 0; i < 9; i++ ) {
                for ( int j = 0; j < 9; j++ ) {
                    int n;
                    cin >> n;
                    if ( n > 0 )
                        fill(p_(0, i, j, n-1));
                }
            }
        }

        void printf() {
            for ( int i = 0; i < 9; i++ ) {
                for ( int j = 0; j < 9; j++ ) {
                    if ( defined[0][i][j] )
                        cout << "[" << value[0][i][j] + 1 << "]";
                    else
                        cout << "[ ]";
                }
                cout << endl;
            }
            cout << endl;
        }

        void reduce() {
            bool changed;
            do {
                changed = false;
                for ( int v = 0; v < 4; v++ ) {
                    for ( int i = 0; i < 9; i++ ) {
                        for ( int j = 0; j < 9; j++ ) {
                            if ( not defined[v][i][j] ) {

                                int cnt = 0;
                                int k0;
                                for ( int k = 0; k < 9; k++ ) {
                                    if ( possible[p_(v, i, j, k)] ) {
                                        cnt++;
                                        k0 = k;
                                    }
                                }

                                if ( cnt == 0 ) {
                                    throw(0);
                                } else if ( cnt == 1 ) {
                                    fill(p_(v, i, j, k0));
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            } while ( changed );
        }

        void solve() {

            reduce();

            int p = 0;
            while ( p < 9*9*9 and (not possible[p]) )
                p++;

            if ( p == 9*9*9 )
                return;
            else {
                sudoku t = *this;
                t.fill(p);
                try {
                    t.solve();
                    *this = t;
                    return;
                }
                catch ( int zero ) {
                    possible[p] = false;
                    solve();
                    return;
                }
            }
        }
};


int main() {

    int sum = 0;
    for ( int cnt = 0; cnt < 50; cnt++ ) {
        sudoku s;
        s.load();
        s.solve();
        sum += (s.value[0][0][0]+1)*100 + (s.value[0][0][1]+1)*10 + (s.value[0][0][2]+1);
    }

    cout << sum << endl;

    return 0;
}
