#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 1786;

int main() {

    string words[SIZE];

    ifstream file;
    file.open("src/0042.txt");
    for (int i = 0; i < SIZE; i++)
        file >> words[i];
    file.close();

    int cnt = 0;
    for ( int i = 0; i < SIZE; i++ ) {

        int sum = 0;
        for (char c : words[i])
            sum += c - 'A' + 1;

        int T = 1;
        int dT = 2;
        while ( T < sum ) {
            T += dT;
            dT++;
        }

        if ( T == sum )
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}
