// 0001.cpp
#include <iostream>
using namespace std;

int main() {

    bool multiple[1000];
    for ( int i = 0; i < 1000; i++ )
        multiple[i] = false;

    for ( int i = 0; 3*i < 1000; i++ )
        multiple[3*i] = true;

    for ( int i = 0; 5*i < 1000; i++ )
        multiple[5*i] = true;

    int sum = 0;
    for ( int i = 0; i < 1000; i++ )
        if ( multiple[i] )
            sum += i;

    cout << sum << endl;

    return 0;
}
