// 0058.cpp
#include <iostream>
#include <bitset>
using namespace std;

const int SIZE = 8e8;      // 素数表のサイズ
static bitset<SIZE> prime; // 素数表

int main() {

    for (int i = 2; i < SIZE; i++)
        prime.set(i);
    for (int i = 2; i * i < SIZE; i++)
        if (prime.test(i))
            for (int j = i * i; j < SIZE; j += i)
                prime.reset(j);

    int size = 1;        // 正方形の一辺の長さ
    int current = 1;     // 現在の数字
    int count = 1;       // 対角線上の個数 (最初は1のみ）
    int prime_count = 0; // 見つかった素数の数
    while (true) {
        size += 2;
        for (int i = 0; i < 4; i++) {
            current += size - 1;
            if (current >= SIZE) {
                cout << "SIZE is too small" << endl;
                return 1;
            }
            count++;
            if (prime.test(current))
                prime_count++;
        }
        if (10 * prime_count < count) {
            cout << size << endl;
            return 0;
        }
    }

    return 1;
}
