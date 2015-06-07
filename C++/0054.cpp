#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int CARD = 13; // 0 -> 2, ..., 8 -> T, 9 -> J, 10 -> Q, 11 -> K, 12 -> A

inline int compute_point(string hand[5]) {

    bool flush = true;
    for (int i = 1; flush and i < 5; i++)
        flush = hand[0].at(1) == hand[i].at(1);

    int count[CARD];
    for (int c = 0; c < CARD; c++)
        count[c] = 0;
    for (int i = 0; i < 5; i++) {
        switch (hand[i].at(0)) {
            case 'A': count[12]++; break;
            case 'K': count[11]++; break;
            case 'Q': count[10]++; break;
            case 'J': count[9]++; break;
            case 'T': count[8]++; break;
            default: count[hand[i].at(0) - '2']++; break;
        }
    }

    bool straight = false;
    int straight_begin = -1;
    for (int c = 5 - 1; c < CARD; c++) {
        bool substraight = true;
        for (int cc = c; substraight and cc > c - 5; cc--)
            substraight = count[cc];
        if (substraight) {
            straight = true;
            straight_begin = c;
            break;
        }
    }
    if (!straight and count[12] and count[0] and count[1] and count[2] and count[3] ) {
        straight = true;
        straight_begin = 3;
    }

    bool four = false;
    for (int c = 0; c < CARD; c++)
        if (count[c] == 4)
            four = true;

    bool three = false;
    for (int c = 0; c < CARD; c++)
        if (count[c] == 3)
            three = true;

    int n_pair = 0;
    for (int c = 0; c < CARD; c++)
        if (count[c] == 2)
            n_pair++;

    int rank        = 0;
    int highest     = 0;
    int highest2    = 0;
    if (flush and straight and straight_begin == 12) {
        rank = 9;
    }
    else if (flush and straight) {
        rank = 8;
        highest = straight_begin;
    }
    else if (four) {
        rank = 7;
        for (highest = CARD - 1; count[highest] != 4; highest--)
            ;
        for (highest2 = CARD - 1; count[highest2] != 1; highest2--)
            ;
    }
    else if (three and n_pair == 1) {
        rank = 6;
        for (highest = CARD - 1; count[highest] != 3; highest--)
            ;
        for (highest2 = CARD - 1; count[highest2] != 2; highest2--)
            ;
    }
    else if (flush) {
        rank = 5;
        for (highest = CARD - 1; count[highest] == 0; highest--)
            ;
        if (count[highest] >= 2)
            highest2 = highest;
        else {
            for (highest2 = highest - 1; count[highest2] == 0; highest2--)
                ;
        }
    }
    else if (straight) {
        rank = 4;
        highest = straight_begin;
    }
    else if (three) {
        rank = 3;
        for (highest = CARD - 1; count[highest] != 3; highest--)
            ;
        for (highest2 = CARD - 1; count[highest2] != 1; highest2--)
            ;
    }
    else if (n_pair == 2) {
        rank = 2;
        for (highest = CARD - 1; count[highest] != 2; highest--)
            ;
        for (highest2 = highest - 1; count[highest2] != 2; highest2--)
            ;
    }
    else if (n_pair == 1) {
        rank = 1;
        for (highest = CARD - 1; count[highest] != 2; highest--)
            ;
        for (highest2 = CARD - 1; count[highest2] != 1; highest2--)
            ;
    }
    else {
        rank = 0;
        for (highest = CARD - 1; count[highest] == 0; highest--)
            ;
        for (highest2 = highest - 1; count[highest2] == 0; highest2--)
            ;
    }


    return (rank * CARD + highest) * CARD + highest2;
}

const int ROUND = 1000;

string cards[ROUND][2][5];

int point[ROUND][2];

int main() {

    ifstream file;
    file.open("src/0054.txt");
    for (int round = 0; round < ROUND; round++)
        for (int player = 0; player < 2; player++)
            for (int i = 0; i < 5; i++)
                file >> cards[round][player][i];
    file.close();

    for (int round = 0; round < ROUND; round++)
        for (int player = 0; player < 2; player++)
            point[round][player] = compute_point(cards[round][player]);

    int count_1_wins = 0;
    for (int round = 0; round < ROUND; round++) {
        if (point[round][0] == point[round][1]) {
            cout << "winner is not clear at round " << round << endl;
            cout << point[round][0] << " vs " << point[round][1] << endl;
            return 1;
        }
        if (point[round][0] > point[round][1])
            count_1_wins++;
    }

    cout << count_1_wins << endl;

    return 0;
}
