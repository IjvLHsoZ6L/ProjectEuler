#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int CODE = 50;
    int code[CODE][3];

    ifstream file;
    file.open("src/0079.txt");
    for ( int i = 0; i < CODE; i++ ) {
        int n;
        file >> n;
        code[i][0] = n / 10 / 10;
        code[i][1] = n / 10 % 10;
        code[i][2] = n % 10;
    }
    file.close();

    bool remain[10];
    bool align[10][10];
    for ( int m = 0; m < 10; m++ ) {
        remain[m] = false;
        for ( int n = 0; n < 10; n++ )
            align[m][n] = false;
    }

    for ( int i = 0; i < CODE; i++ ) {
        remain[code[i][0]] = remain[code[i][1]] = remain[code[i][2]] = true;
        align[code[i][0]][code[i][1]] = true;
        align[code[i][0]][code[i][2]] = true;
        align[code[i][1]][code[i][2]] = true;
    }

    int length = 0;
    for ( int m = 0; m < 10; m++ )
        length += remain[m] ? 1 : 0;

    int pass[length];
    for ( int k = 0; k < length; k++ ) {

        bool detected = false;
        for ( int m = 0; not detected; m++ ) {
            if ( remain[m] ) {

                bool left = true;
                for ( int n = 0; n < 10; n++ )
                    left = left and (not (remain[n] and align[n][m]));

                if ( left ) {
                    detected = true;
                    pass[k] = m;
                    remain[m] = false;
                }
            }
        }
    }

    for ( int k = 0; k < length; k++ )
        cout << pass[k];
    cout << endl;

    return 0;
}
