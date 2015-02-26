// 0116.cpp
#include <iostream>
using namespace std;

int main() {

    int length = 50;

    long long red[length + 1], green[length + 1], blue[length + 1];

    red[0] = red[1] = 1;
    for ( int l = 2; l <= length; l++ )
        red[l] = red[l - 1] + red[l - 2];

    green[0] = green[1] = green[2] = 1;
    for ( int l = 3; l <= length; l++ )
        green[l] = green[l - 1] + green[l - 3];


    blue[0] = blue[1] = blue[2] = blue[3] = 1;
    for ( int l = 4; l <= length; l++ )
        blue[l] = blue[l - 1] + blue[l - 4];

    cout << (red[length] - 1) + (green[length] - 1) + (blue[length] - 1) << endl;

    return 0;
}
