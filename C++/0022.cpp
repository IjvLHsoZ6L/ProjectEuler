#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 5163;

int main() {

    string name[SIZE];

    ifstream file;
    file.open("src/0022.txt");
    for ( int i = 0; i < SIZE; i++ )
        file >> name[i];
    file.close();

    for ( int i = 0; i < SIZE; i++ ) {
        for ( int j = 0; j + 1 < SIZE - i; j++ ) {
            if ( name[j] > name[j + 1] ) {
                string temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }

    int sum = 0;
    for ( int i = 0; i < SIZE; i++ ) {

        int score = 0;
        for (char c : name[i])
            score += c - 'A' + 1;

        sum += score * (i + 1);
    }

    cout << sum << endl;

    return 0;
}
