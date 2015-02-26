// 0006.cpp
#include <iostream>
using namespace std;

int main() {

    int sum = 0, sumofsquare = 0;
    for ( int i = 1; i <= 100; i++ ) {
        sum += i;
        sumofsquare += i*i;
    }

    cout << sum*sum - sumofsquare << endl;

    return 0;
}
