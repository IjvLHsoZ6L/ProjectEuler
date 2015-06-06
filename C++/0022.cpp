// 0022.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream file("0022.txt");

    int size = 5163;

    string name[size];
    for ( int i = 0; i < size; i++ )
        file >> name[i];

    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j + 1 < size - i; j++ ) {
            if ( name[j] > name[j + 1] ) {
                string temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }

    int sum = 0;
    for ( int i = 0; i < size; i++ ) {

        int score = 0;
        for (char c : name[i])
            score += c - 'A' + 1;

        sum += score * (i + 1);
    }

    cout << sum << endl;

    return 0;
}
