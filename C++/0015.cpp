// 0015.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 20;

    long long routes[size+1][size+1];
    for ( int i = 0; i <= size; i++ )
        routes[i][0] = routes[0][i] = 1;

    for ( int i = 1; i <= size; i++ )
        for ( int j = 1; j <= size; j++ )
            routes[i][j] = routes[i-1][j] + routes[i][j-1];

    cout << routes[size][size] << endl;

    return 0;
}
