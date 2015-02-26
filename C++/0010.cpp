// 0010.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 2e6;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    long long sum = 0;
    for ( int i = 0; i < target; i++ )
        if ( prime[i] )
            sum += i;

    cout << sum << endl;

    return 0;
}
