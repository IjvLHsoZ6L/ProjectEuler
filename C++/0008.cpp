// 0008.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1000;

    int value[size];
    for ( int i = 0; i < size; i++ )
        cin >> value[i];

    int max = 0;
    for ( int i = 0; i+5 <= size; i++ ) {

        int product = 1;
        for ( int j = 0; j < 5; j++ )
            product *= value[i + j];

        if ( max < product )
            max = product;
    }

    cout << max << endl;

    return 0;
}
