// 0024.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 10;
    int order = 1000000-1;

    int align[size];
    for ( int k = 1; k <= size; k++ ) {
        align[size - k] = order % k;
        order /= k;
    }

    bool remain[size];
    for ( int i = 0; i < size; i++ )
        remain[i] = true;

    for ( int i = 0; i < size; i++ ) {

        int j = -1;
        for ( int k = 0; k <= align[i]; k++ ) {
            j++;
            while ( not remain[j] )
                j++;
        }

        align[i] = j;
        remain[j] = false;
    }

    for ( int i = 0; i < size; i++ )
        cout << align[i];
    cout << endl;

    return 0;
}
