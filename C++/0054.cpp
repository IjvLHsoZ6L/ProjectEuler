// 054.cpp
#include <iostream>
using namespace std;

int main() {

    int size = 1000;

    string hand[size][2][5];
    for ( int i = 0; i < size; i++ )
        for ( int p = 0; p < 2; p++ )
            for ( int c = 0; c < 5; c++ )
                cin >> hand[i][p][c];

    int point[size][2];
    for ( int i = 0; i < size; i++ ) {
        for ( int p = 0; p < 2; p++ ) {

            bool flush = true;
            for ( int c = 1; c < 5; c++ )
                flush = flush and (hand[i][p][0].at(1) == hand[i][p][c].at(1));

            int app[15];
            for ( int j = 0; j < 15; j++ )
                app[j] = 0;

            for ( int c = 0; c < 5; c++ ) {
                switch ( hand[i][p][c].at(0) ) {
                    case 'A': app[14]++; break;
                    case 'K': app[13]++; break;
                    case 'Q': app[12]++; break;
                    case 'J': app[11]++; break;
                    case 'T': app[10]++; break;
                    default: app[hand[i][p][c].at(0)-'0']++; break;
                }
            }

            bool royal = true;
            for ( int value = 10; value < 15; value++ )
                royal = royal and (app[value] == 1);

            bool straight = false;
            for ( int value = 2; value < 10; value++ ) {
                bool substraight = true;
                for ( int j = 0; j < 5; j++ )
                    substraight = substraight and (app[value+j] == 1);
                if ( substraight )
                    straight = true;
            }

            bool four = false;
            for ( int value = 2; value < 15; value++ )
                if ( app[value] == 4 )
                    four = true;

            bool three = false;
            for ( int value = 2; value < 15; value++ )
                if ( app[value] == 3 )
                    three = true;

            bool pair = false;
            bool twop = false;
            int cnt = 0;
            for ( int value = 14; value >= 2; value-- )
                if ( app[value] == 2 )
                    cnt++;
            if ( cnt == 1 )
                pair = true;
            if ( cnt == 2 )
                twop = true;

            int rank = 0;
            int first = 0;
            int second = 0;
            if ( royal and flush )
                rank = 9;
            else if ( straight and flush ) {
                rank = 8;
                first = 14;
                while ( app[first] == 0 )
                    first--;
            }
            else if ( four ) {
                rank = 7;
                while ( app[first] < 4 )
                    first++;
            }
            else if ( three and pair ) {
                rank = 6;
                while ( app[first] < 3 )
                    first++;
            }
            else if ( flush ) {
                rank = 5;
                first = 14;
                while ( app[first] == 0 )
                    first--;
                second = first - 1;
                while ( app[second] == 0 )
                    second--;
            }
            else if ( straight ) {
                rank = 4;
                first = 14;
                while ( app[first] == 0 )
                    first--;
            }
            else if ( three ) {
                rank = 3;
                while ( app[first] < 3 )
                    first++;
            }
            else if ( twop ) {
                rank = 2;
                first = 14;
                while ( app[first] < 2 )
                    first--;
                second = first - 1;
                while ( app[second] < 2 )
                    second--;
            }
            else if ( pair ) {
                rank = 1;
                first = 14;
                while ( app[first] < 2 )
                    first--;
                second = 14;
                while ( app[second] != 1 )
                    second--;
            }
            else {
                rank = 0;
                first = 14;
                while ( app[first] < 1 )
                    first--;
                second = first - 1;
                while ( app[second] < 1 )
                    second--;
            }

            point[i][p] = rank*10000 + first*100 + second;
        }
    }

    int cnt = 0;
    for ( int i = 0; i < size; i++ )
        if ( point[i][0] == point[i][1] )
            cout << "same score at the game " << i << endl;
        else if ( point[i][0] > point[i][1] )
            cnt++;

    cout << cnt++ << endl;

    return 0;
}
