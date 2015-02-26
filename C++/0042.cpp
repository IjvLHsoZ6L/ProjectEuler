// 0042.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1786;

    int cnt = 0;
    for ( int i = 0; i < size; i++ ) {

        string str;
        cin >> str;

        int sum = 0;
        for ( int j = 0; j < str.length(); j++ )
            sum += str.at(j) - 'A' + 1;

        int T = 1;
        int dT = 2;
        while ( T < sum ) {
            T += dT;
            dT++;
        }

        if ( T == sum )
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}
