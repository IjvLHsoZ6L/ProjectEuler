#include <iostream>
#include <fstream>

using namespace std;

inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    int SIZE = 80;
    int a[SIZE][SIZE];

    ifstream file;
    file.open("src/0081.txt");
    for ( int i = 0; i < SIZE; i++ )
        for ( int j = 0; j < SIZE; j++ )
            file >> a[i][j];
    file.close();

    for ( int i = 1; i < SIZE; i++ )
        a[i][0] += a[i - 1][0];

    for ( int j = 1; j < SIZE; j++ )
        a[0][j] += a[0][j - 1];

    for ( int i = 1; i < SIZE; i++ )
        for ( int j = 1; j < SIZE; j++ )
            a[i][j] += min(a[i - 1][j], a[i][j - 1]);

    cout << a[SIZE - 1][SIZE - 1] << endl;

    return 0;
}
