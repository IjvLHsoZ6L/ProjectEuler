// 0007.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 200000;

    bool prime[size];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < size; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < size; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < size; j++ )
                prime[i*j] = false;

    int i = -1;
    for ( int cnt = 0; cnt < 10001; cnt++ ) {
        i++;
        while ( not prime[i] )
            i++;
    }

    cout << i << endl;

    return 0;
}
