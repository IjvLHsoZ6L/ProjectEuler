#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 15;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    int array[SIZE][SIZE];

    ifstream file;
    file.open("src/0018.txt");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j <= i; j++)
            file >> array[i][j];
    file.close();

    for (int i = SIZE - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            array[i][j] += max(array[i + 1][j], array[i + 1][j + 1]);

    cout << array[0][0] << endl;

    return 0;
}
