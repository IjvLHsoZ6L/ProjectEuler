// 0028.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1001;

    int sum = 1;
    for ( int l = 3; l <= size; l += 2 )
        for ( int i = 0; i < 4; i++ )
            sum += l*l - (l - 1)*i;

    cout << sum << endl;

    return 0;
}
