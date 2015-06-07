#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include <set>

using namespace std;

inline bool is_special(list<int> as) {
    int n = as.size();
    int array[n]; {
        int i = 0;
        for (int a : as) {
            array[i] = a;
            i++;
        }
        for (int i = n; i > 0; i--)
            for (int j = 0; j + 1 < i; j++)
                if (array[j] > array[j + 1])
                    swap(array[j], array[j + 1]);
    }
    int i = 1;
    int j = 0;
    int sum_A = array[0];
    int sum_B = 0;
    while (true) {
        i++;
        j++;
        if (i + j > n)
            break;
        sum_A += array[i - 1];
        sum_B += array[n - j];
        if (sum_A < sum_B)
            return false;
    }
    set<int> sums; {
        sums.insert(0);
    }
    list<int> queue;
    for (int a : as) {
        queue.clear();
        for (int s : sums)
            queue.push_back(s);
        for (int s : queue) {
            if (sums.count(s + a) > 0)
                return false;
            sums.insert(s + a);
        }
    }
    return true;
}

inline int sum(list<int> as) {
    int s = 0;
    for (int a : as)
        s += a;
    return s;
}

const int SIZE = 100;

int main() {

    list<int> data[SIZE]; {
        ifstream file;
        file.open("src/0105.txt");
        for (int i = 0; i < SIZE; i++) {
            while (true) {
                int n;
                file >> n;
                data[i].push_back(n);
                if (file.peek() == ',') {
                    file.ignore(1);
                    continue;
                }
                break;
            }
        }
        file.close();
    }

    int total_sum = 0; {
        for (int i = 0; i < SIZE; i++)
            if (is_special(data[i]))
                total_sum += sum(data[i]);
    }

    cout << total_sum << endl;

    return 0;
}
