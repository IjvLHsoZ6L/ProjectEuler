#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<string, vector<string>> word_map;

inline string sort(string str) {
    for (int i = str.length(); i > 0; i--)
        for (int j = 0; j + 1 < i; j++)
            if (str[j] > str[j + 1])
                swap(str[j], str[j + 1]);
    return str;
}
inline void add_word(string word) {
    string sorted = sort(word);
    if (word_map.find(sorted) == word_map.end())
        word_map.insert(pair<string, vector<string>>(sorted, *(new vector<string>)));
    word_map.find(sorted)->second.push_back(word);
}
inline void read_file() {
    ifstream ifs;
    ifs.open("src/0098.txt");
    while (true) {
        ifs.ignore();
        string word;
        getline(ifs, word, '"');
        add_word(word);
        if (ifs.eof())
            break;
        ifs.ignore();
    }
    ifs.close();
    for (pair<string, vector<string>> p : word_map)
        if (p.second.size() <= 1)
            word_map.erase(p.first);
}
inline bool is_square(int num) {
    return pow(round(sqrt(num)), 2) == num;
}

int main() {

    read_file();

    int max_length = -1;
    for (pair<string, vector<string>> p : word_map)
        max_length = max(max_length, (int)p.first.length());

    for (int r = (int)floor(sqrt(pow(10, max_length) - 1)); r > 0; r--) {
        string square = to_string(r * r);
        int length = square.length();
        for (pair<string, vector<string>> p : word_map) {
            if ((int)p.first.length() != length)
                continue;
            for (string word : p.second) {
                bool valid = true;
                for (int i = 0; i < length; i++)
                    for (int j = i + 1; j < length; j++)
                        if ((word[i] == word[j]) xor (square[i] == square[j]))
                            valid = false;
                if (!valid)
                    continue;
                int index[26];
                for (int i = 0; i < length; i++)
                    index[word[i] - 'A'] = square[i] - '0';
                for (string another : p.second) {
                    if (word == another)
                        continue;
                    if (index[another[0] - 'A'] == 0)
                        continue;
                    int num = 0;
                    for (char c : another)
                        num = num * 10 + index[c - 'A'];
                    if (is_square(num)) {
                        cout << square << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}
