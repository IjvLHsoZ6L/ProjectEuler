#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 1786;

int main() {

    string word[SIZE];

    ifstream file;
    file.open("src/0098.txt");
    for ( int i = 0; i < SIZE; i++ )
        file >> word[i];
    file.close();

    int length[SIZE];
    for ( int i = 0; i < SIZE; i++ )
        length[i] = word[i].length();

    int appear[SIZE][26];
    for ( int i = 0; i < SIZE; i++ ) {
        for ( int a = 0; a < 26; a++ )
            appear[i][a] = 0;
        for ( int l = 0; l < length[i]; l++ )
            appear[i][word[i].at(l) - 'A']++;
    }

    const int MAX = 1e9;
    static bool square[MAX];
    for ( int s = 0; s < MAX; s++ )
        square[s] = false;
    for ( int r = 0; r*r < MAX; r++ )
        square[r*r] = true;

    int max = 0;
    for ( int i = 0; i < SIZE; i++ ) {
        for ( int j = i+1; j < SIZE; j++ ) {
            if ( length[i] == length[j] ) {
                bool coincide = true;
                for ( int a = 0; a < 26; a++ )
                    coincide and_eq (appear[i][a] == appear[j][a]);
                if ( coincide ) {

                    int n = 0;
                    for ( int a = 0; a < 26; a++ )
                        if ( appear[i][a] > 0 )
                            n++;

                    int choice = 1;
                    for ( int k = 0; k < n; k++ )
                        choice *= 10 - k;

                    for ( int c = 0; c < choice; c++ ) {

                        int remain[10];
                        for ( int d = 0; d < 10; d++ )
                            remain[d] = true;

                        int C = c;
                        int k = 0;
                        int num[26];
                        for ( int a = 0; a < 26; a++ ) {
                            if ( appear[i][a] > 0 ) {
                                num[a] = C % (10 - k);
                                C /= 10 - k;

                                int d = 0;
                                for ( int cnt = 0; cnt <= num[a]; d++ )
                                    if ( remain[d] )
                                        cnt++;
                                d--;
                                remain[d] = false;
                                num[a] = d;

                                k++;
                            }
                        }

                        if ( num[word[i].at(0) - 'A'] > 0 and num[word[j].at(0) - 'A'] > 0 ) {

                            int sq1 = 0;
                            for ( int l = 0; l < length[i]; l++ )
                                sq1 = sq1*10 + num[word[i].at(l) - 'A'];

                            if ( square[sq1] ) {

                                int sq2 = 0;
                                for ( int l = 0; l < length[j]; l++ )
                                    sq2 = sq2*10 + num[word[j].at(l) - 'A'];

                                if ( square[sq2] ) {
                                    if ( max < sq1 )
                                        max = sq1;
                                    if ( max < sq2 )
                                        max = sq2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}
