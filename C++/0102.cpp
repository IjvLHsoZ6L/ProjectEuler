#include <iostream>
#include <fstream>

using namespace std;

inline bool contains_origin(int x[3], int y[3]) {
    bool cc[3];
    for (int i = 0; i < 3; i++) {
        int ii = (i + 1) % 3;
        cc[i] = x[i] * y[ii] - x[ii] * y[i] > 0;
    }
    return (cc[0] && cc[1] && cc[2]) || (!cc[0] && !cc[1] && !cc[2]);
}

const int SIZE = 1000;

int main() {

    int x[SIZE][3], y[SIZE][3];

    ifstream file;
    file.open("src/0102.txt");
    for (int i = 0; i < SIZE; i++) {
        for ( int j = 0; j < 3; j++ ) {
            file >> x[i][j];
            file >> y[i][j];
        }
    }
    file.close();

    int count = 0;
    for (int i = 0; i < SIZE; i++)
        if (contains_origin(x[i], y[i]))
            count++;

    cout << count << endl;

    return 0;
}
