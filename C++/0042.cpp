// 0042.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file("0042.txt");

    int size = 1786;

    int cnt = 0;
    for ( int i = 0; i < size; i++ ) {

        string str;
        file >> str;

        int sum = 0;
        for (char c : str)
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
