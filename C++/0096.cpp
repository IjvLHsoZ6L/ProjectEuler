#include <iostream>
#include <fstream>
#include <bitset>
#include <array>
#include <list>
#include <set>

using namespace std;

const int BOX_SIZE  = 3;
const int DIGIT     = BOX_SIZE * BOX_SIZE;
const int COORD     = DIGIT * DIGIT * DIGIT;
const int BLOCK     = 4 * DIGIT * DIGIT;

const int DEFINED = 99;

const int NO_SOLUTION = 666;

array<list<int>, BLOCK> coords;
array<list<int>, COORD> owners;
array<list<int>, COORD> others;

inline int to_coord(int i, int j, int d) {
    return (i * DIGIT + j) * DIGIT + d;
}

inline int to_block(int v, int p, int q) {
    return (v * DIGIT + p) * DIGIT + q;
}

void initialize() {
    for (int i = 0; i < DIGIT; i++) {
        for (int j = 0; j < DIGIT; j++) {
            for (int d = 0; d < DIGIT; d++) {
                int c = to_coord(i, j, d);
                int p = i / BOX_SIZE * BOX_SIZE + j / BOX_SIZE;
                coords[to_block(0, i, j)].push_back(c);
                coords[to_block(1, i, d)].push_back(c);
                coords[to_block(2, j, d)].push_back(c);
                coords[to_block(3, p, d)].push_back(c);
            }
        }
    }
    for (int b = 0; b < BLOCK; b++)
        for (int c : coords[b])
            owners[c].push_back(b);
    for (int coord = 0; coord < COORD; coord++) {
        set<int> cs;
        for (int b : owners[coord])
            for (int c : coords[b])
                cs.insert(c);
        cs.erase(coord);
        for (int c : cs)
            others[coord].push_back(c);
    }
}

class sudoku {
    private:
        bitset<COORD> possible;
        array<int, BLOCK> options;
    public:
        sudoku() {
            clear();
        }
        sudoku(const sudoku & sudoku) {
            copy(sudoku);
        }
        sudoku & read(istream & input) {
            for (int i = 0; i < DIGIT; i++) {
                for (int j = 0; j < DIGIT; j++) {
                    int d;
                    input >> d;
                    if (d > 0) {
                        d--;
                        assign(to_coord(i, j, d));
                    }
                }
            }
            return *this;
        }
        sudoku & solve() {
            int b_min = -1;
            int min = DEFINED;
            for (int b = 0; b < BLOCK; b++)
                if (options[b] < min)
                    min = options[b_min = b];
            if (min == DEFINED)
                return *this;
            sudoku saved = *this;
            for (int c : coords[b_min]) {
                try {
                    return copy(saved).assign(c).solve();
                }
                catch (int no_solution) {
                    continue;
                }
            }
            throw NO_SOLUTION;
        }

        int top_left() {
            int d[3];
            int i = 0;
            for (int j = 0; j < 3; j++) {
                d[j] = 0;
                while (!possible[to_coord(i, j, d[j])] && d[j] < DIGIT)
                    d[j]++;
                if (d[j] == DIGIT)
                    throw "top_left: illegal sudoku object";
                d[j]++;
            }
            return (d[0] * 10 + d[1]) * 10 + d[2];
        }
        sudoku & clear() {
            for (int c = 0; c < COORD; c++)
                possible[c] = true;
            for (int b = 0; b < BLOCK; b++)
                options[b] = DIGIT;
            return *this;
        }
        sudoku & copy(const sudoku & sudoku) {
            for (int c = 0; c < COORD; c++)
                possible[c] = sudoku.possible[c];
            for (int b = 0; b < BLOCK; b++)
                options[b] = sudoku.options[b];
            return *this;
        }
    private:
        sudoku & assign(int coord) {
            if (!possible[coord])
                throw NO_SOLUTION;
            list<int> cs;
            for (int c : others[coord])
                if (possible[c])
                    cs.push_back(c);
            list<int> bs;
            for (int c : cs)
                for (int b : owners[c])
                    bs.push_back(b);
            for (int c : cs)
                possible[c] = false;
            for (int b : bs)
                options[b]--;
            for (int b : owners[coord])
                options[b] = DEFINED;
            for (int b : bs)
                check(b);
            return *this;
        }
        sudoku & check(int block) {
            if (options[block] == 0)
                throw NO_SOLUTION;
            if (options[block] == 1) {
                int coord = -1;
                for (int c : coords[block])
                    if (possible[c])
                        coord = c;
                if (coord == -1)
                    throw "check: illegal sudoku object";
                return assign(coord);
            }
            return *this;
        }
};

int main() {
    initialize();
    ifstream file("src/0096.txt");
    int sum = 0;
    sudoku sudoku;
    for (int i = 0; i < 50; i++) {
        try {
            sum += sudoku.clear().read(file).solve().top_left();
        }
        catch (int no_solution) {
            cout << "at i = " << i << ": no solution" << endl;
            return 1;
        }
        catch (const char* s) {
            cout << "at i = " << i << ": Error " << s << endl;
            return 1;
        }
    }
    cout << sum << endl;
    return 0;
}
