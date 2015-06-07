#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE  = 100;
const int DIGIT = 50;

int main() {

    int array[SIZE][DIGIT];

    ifstream file;
    file.open("src/0013.txt");
    for (int i = 0; i < SIZE; i++) {
        string string;
        file >> string;
        for (int j = 0; j < DIGIT; j++)
            array[i][j] = string.at(j) - '0';
    }
    file.close();

    int sum[DIGIT];
    for (int j = 0; j < DIGIT; j++)
        sum[j] = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < DIGIT; j++)
            sum[j] += array[i][j];
    for (int j = DIGIT - 1; j > 0; j--) {
        sum[j - 1] += sum[j] / 10;
        sum[j] %= 10;
    }

    string result;
    for (int j = 0; result.length() < 10; j++)
        result += to_string(sum[j]);

    cout << result << endl;
}
