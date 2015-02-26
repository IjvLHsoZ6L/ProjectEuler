// 0019.cpp
#include <iostream>
using namespace std;

int main() {

    int days[101][13];
    for ( int year = 1; year <= 100; year++ ) {
        days[year][1] = 31;
        days[year][2] = (year % 4 == 0 ? 29 : 28);
        days[year][3] = 31;
        days[year][4] = 30;
        days[year][5] = 31;
        days[year][6] = 30;
        days[year][7] = 31;
        days[year][8] = 31;
        days[year][9] = 30;
        days[year][10] = 31;
        days[year][11] = 30;
        days[year][12] = 31;
    }

    int week = (1+366)%7;
    int cnt = 0;
    for ( int year = 1; year <= 100; year++ ) {
        for ( int month = 1; month <= 12; month++ ) {
            if ( week == 0 )
                cnt++;
            week += days[year][month];
            week %= 7;
        }
    }

    cout << cnt << endl;

    return 0;
}
