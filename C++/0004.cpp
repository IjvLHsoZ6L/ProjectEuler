// 0004.cpp
#include <iostream>
using namespace std;

int main() {

    static bool palindrome[1000000];
    for ( int i = 100000; i <= 999999; i++ )
        palindrome[i] = false;

    for ( int i = 1; i < 10; i++ )
        for ( int j = 0; j < 10; j++ )
            for ( int k = 0; k < 10; k++ )
                palindrome[100001*i + 10010*j + 1100*k] = true;

    static bool multiple[1000000];
    for ( int i = 100000; i <= 999999; i++ )
        multiple[i] = false;

    for ( int i = 100; i <= 999; i++ )
        for ( int j = i; j <= 999; j++ )
            multiple[i*j] = true;

    int max = 0;
    for ( int i = 100000; i <= 999999; i++ )
        if ( palindrome[i] and multiple[i] )
            max = i;

    cout << max << endl;

    return 0;
}
