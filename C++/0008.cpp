#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 1000;
const int ROW  = 20;
const int COL  = 50;

const int LENGTH = 13;

int main() {

    int numbers[SIZE];

    ifstream file;
    string string;
    file.open("src/0008.txt");
    for (int i = 0; i < ROW; i++) {
        file >> string;
        for (int j = 0; j < COL; j++)
            numbers[i * COL + j] = (int)(string.at(j) - '0');
    }
    file.close();

    long max = 0;
    for (int i = 0; i + LENGTH - 1 < SIZE; i++) {
        long product = 1;
        for (int j = i; j < i + LENGTH; j++)
            product *= numbers[j];
        if (product > max)
            max = product;
    }

    cout << max << endl;

    return 0;
}
