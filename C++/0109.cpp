// 0109.cpp
#include <iostream>
using namespace std;

int main() {

    int regions = 3 * 20 + 2;

    int score[regions + 1];
    for ( int m = 1; m <= 3; m++ )
        for ( int p = 1; p <= 20; p++ )
            score[(m - 1) * 20 + p] = m * p;
    for ( int m = 1; m <= 2; m++ )
        score[3 * 20 + m] = m * 25;

    int size = 170;

    int twodarts[size + 1];
    for ( int s = 0; s <= size; s++ )
        twodarts[s] = 0;

    twodarts[0]++;

    for ( int i = 1; i <= regions; i++ )
        twodarts[score[i]]++;

    for ( int i = 1; i <= regions; i++ )
        for ( int j = 1; j <= i; j++ )
            twodarts[score[i] + score[j]]++;

    int threedarts[size + 1];
    for ( int s = 0; s <= size; s++ )
        threedarts[s] = 0;

    for ( int p = 1; p <= 20; p++ )
        for ( int s = 0; s + 2 * p <= size; s++ )
            threedarts[s + 2 * p] += twodarts[s];

    for ( int s = 0; s + 2 * 25 <= size; s++ )
        threedarts[s + 2 * 25] += twodarts[s];

    int sum = 0;
    for ( int s = 0; s < 100; s++ )
        sum += threedarts[s];

    cout << sum << endl;

    return 0;
}
