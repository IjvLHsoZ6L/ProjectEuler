#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int size = 100;
    int x[size][size];

    ifstream file;
    file.open("src/0067.txt");
    for ( int i = 0; i < size; i++ )
        for ( int j = 0; j <= i; j++ )
            file >> x[i][j];
    file.close();

    for ( int i = size-2; i >= 0; i-- )
        for ( int j = 0; j <= i; j++ )
            x[i][j] += ((x[i+1][j] < x[i+1][j+1]) ? x[i+1][j+1] : x[i+1][j]);

    cout << x[0][0] << endl;

    return 0;
}
