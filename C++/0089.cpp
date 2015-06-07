#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 1000;

int main() {

    string data[SIZE];

    ifstream file;
    file.open("src/0089.txt");
    for (int i = 0; i < SIZE; i++)
        file >> data[i];
    file.close();

    int saved = 0;
    for ( int i = 0; i < SIZE; i++ ) {

        string roman = data[i];

        saved += roman.length();

        int value = 0;
        int j = roman.length() - 1;

        while ( j >= 0 and roman.at(j) == 'I' ) {
            value += 1;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'V' and roman.at(j-1) == 'I' ) {
            value += 4;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'V' ) {
            value += 5;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'X' and roman.at(j-1) == 'I' ) {
            value += 9;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'X' ) {
            value += 10;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'L' and roman.at(j-1) == 'X' ) {
            value += 40;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'L' ) {
            value += 50;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'C' and roman.at(j-1) == 'X' ) {
            value += 90;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'C' ) {
            value += 100;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'D' and roman.at(j-1) == 'C' ) {
            value += 400;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'D' ) {
            value += 500;
            j--;
        }

        if ( j > 0 and roman.at(j) == 'M' and roman.at(j-1) == 'C' ) {
            value += 900;
            j -= 2;
        }

        while ( j >= 0 and roman.at(j) == 'M' ) {
            value += 1000;
            j--;
        }

        for ( int cnt = 0; cnt < 3; cnt++ ) {
            switch ( value % 10 ) {
                case 0: saved -= 0; break;
                case 1: saved -= 1; break;
                case 2: saved -= 2; break;
                case 3: saved -= 3; break;
                case 4: saved -= 2; break;
                case 5: saved -= 1; break;
                case 6: saved -= 2; break;
                case 7: saved -= 3; break;
                case 8: saved -= 4; break;
                case 9: saved -= 2; break;
            }

            value /= 10;
        }

        saved -= value;
    }

    cout << saved << endl;

    return 0;
}
