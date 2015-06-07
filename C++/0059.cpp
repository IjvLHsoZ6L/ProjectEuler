#include <iostream>
#include <fstream>
#include <list>

using namespace std;

inline int the_count(char text[], int length) {
    int count = 0;
    for (int i = 0; i + 2 < length; i++)
        if (text[i] == 't' and text[i + 1] == 'h' and text[i + 2] == 'e')
            count++;
    return count;
};

int main() {

    list<int> input; {
        int i;
        char c;
        ifstream file;
        file.open("src/0059.txt");
        while (true) {
            file >> i;
            input.push_back(i);
            if (file.eof())
                break;
            file >> c;
        }
        file.close();
    }

    int length = input.size();

    char encrypted[length]; {
        int i = 0;
        for (int n : input) {
            encrypted[i] = n;
            i++;
        }
    }

    int max_count_the = 0;
    int best_sum = -1;
    char key[3];
    char decrypted[length];
    for (key[0] = 'a'; key[0] <= 'z'; key[0]++) {
        for (key[1] = 'a'; key[1] <= 'z'; key[1]++) {
            for (key[2] = 'a'; key[2] <= 'z'; key[2]++) {
                for (int i = 0; i < length; i++)
                    decrypted[i] = encrypted[i] ^ key[i % 3];
                int count = the_count(decrypted, length);
                if (count > max_count_the) {
                    max_count_the = count;
                    best_sum = 0;
                    for (int i = 0; i < length; i++)
                        best_sum += decrypted[i];
                }
            }
        }
    }

    cout << best_sum << endl;

    return 0;
}
