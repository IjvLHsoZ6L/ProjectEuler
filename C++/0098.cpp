#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

map<string, vector<string>> words;

inline string sort(string s) {
    for (int i = s.length(); i > 0; i--) {
        for (int j = 0; j + 1 < i; j++) {
            if (s[j] > s[j + 1]) {
                char c = s[j];
                s[j] = s[j + 1];
                s[j + 1] = c;
            }
        }
    }
    return s;
}

inline void add_string(string s) {
    string sorted = sort(s);
    if (words.find(sorted) == words.end())
        words.insert(pair<string, vector<string>>(sorted, *(new vector<string>)));
    words.find(sorted)->second.push_back(s);
}

inline void read_file() {
    ifstream file;
    file.open("src/0098.txt");
    while (!file.eof()) {
        file.ignore();
        string s;
        getline(file, s, '"');
        add_string(s);
        file.ignore();
    }
    file.close();
}

inline bool is_square(int n) {
    int r = round(sqrt(n));
    return r * r == n;
}

inline void check(string s, string t, int & longest, int & largest) {

    if ((int)s.length() < longest)
        return;

    set<char> char_set;
    for (int c : s)
        char_set.insert(c);

    int n_char = char_set.size();

    int n_choice = 1;
    for (int i = 0; i < n_char; i++)
        n_choice *= 10 - i;

    int index[26];
    {
        int i = 0;
        for (int c : char_set) {
            index[c - 'A'] = i;
            i++;
        }
    }

    bool remains[10];
    int assign[n_char];
    for (int n = 0; n < n_choice; n++) {

        for (int d = 0; d < 10; d++)
            remains[d] = true;
        for (int m = n, i = 0; i < n_char; m /= 10 - i, i++) {
            int d = -1;
            for (int j = 0, k = m % (10 - i); j <= k; j++) {
                d++;
                while (!remains[d])
                    d++;
            }
            assign[i] = d;
            remains[d] = false;
        }
        if (assign[index[s[0] - 'A']] == 0)
            continue;
        if (assign[index[t[0] - 'A']] == 0)
            continue;

        int n_s = 0;
        for (char c : s)
            n_s = n_s * 10 + assign[index[c - 'A']];

        if (is_square(n_s)) {

            int n_t = 0;
            for (char c : t)
                n_t = n_t * 10 + assign[index[c - 'A']];

            if (is_square(n_t)) {
                longest = int(s.length());
                largest = max(largest, max(n_s, n_t));
            }
        }
    }
}

int main() {

    read_file();

    int longest = -1;
    int largest = -1;
    for (pair<string, vector<string>> p : words) {
        vector<string> & vec = p.second;
        for (int i = 0; i < (int)vec.size(); i++)
            for (int j = i + 1; j < (int)vec.size(); j++)
                check(vec[i], vec[j], longest, largest);
    }

    cout << largest << endl;

    return 0;
}
