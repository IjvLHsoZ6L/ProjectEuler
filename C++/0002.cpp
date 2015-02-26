// 0002.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 4e6;
    int size = 1000;

    int fibonacci[size];
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for ( int i = 2; fibonacci[i-1] <= target; i++ )
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    int sum = 0;
    for ( int i = 0; fibonacci[i] <= target; i++ )
        if ( fibonacci[i] % 2 == 0 )
            sum += fibonacci[i];

    cout << sum << endl;

    return 0;
}
