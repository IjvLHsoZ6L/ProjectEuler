#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> words;

string sort(string s) {
    for (int l = s.length(), i = l; i > 0; i--) {
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

void add_word(string s) {
    string sorted = sort(s);
    if (words.find(sorted) == words.end())
        words.insert(pair<string, vector<string>>(sorted, *(new vector<string>)));
    words.find(sorted)->second.push_back(s);
}

void read_file() {
    ifstream file;
    file.open("src/0098.txt");
    while (!file.eof()) {
        file.ignore();
        string s;
        getline(file, s, '"');
        add_word(s);
        file.ignore();
    }
    file.close();
}

void check(string s, string t, int * largest) {
}

int main() {

    read_file();

    int largest = -1;
    for (pair<string, vector<string>> pair : words) {
        vector<string> & vec = pair.second;
        for (int l = vec.size(), i = 0; i < l; i++)
            for (int j = i + 1; j < l; j++)
                check(vec[i], vec[j], & largest);
    }

    cout << largest << endl;

    return 1;
}
