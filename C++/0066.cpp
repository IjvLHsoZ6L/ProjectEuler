// 0066.cpp
#include <iostream>
using namespace std;

class BigInt {
  private:
    static int const SIZE = 0x100;
    static int const UNIT = 0x100;
    int _[SIZE];
    void carry() {
      for (int i = 0; i + 1 < SIZE; i++) {
        _[i + 1] += _[i] / UNIT;
        _[i] %= UNIT;
      }
    }
  public:
    BigInt() {
    }
    BigInt(int n) {
      _[0] = n;
      carry();
    }
    BigInt operator+(BigInt that) {
      BigInt sum = 0;
      for (int i = 0; i < SIZE; i++)
        sum._[i] = _[i] + that._[i];
      sum.carry();
      return sum;
    }
    BigInt operator*(int n) {
      BigInt prod = 0;
      for (int i = 0; i < SIZE; i++)
        prod._[i] = _[i] * n;
      prod.carry();
      return prod;
    }
    bool operator<(BigInt that) {
      int i = SIZE - 1;
      while (i > 0 && _[i] == that._[i])
        i--;
      return _[i] < that._[i];
    }
};

int main() {

  int const SIZE = 0x100;
  int resiredD;
  BigInt maximumMinimumX = 0;

  for (int D = 0, n = 0; D <= 1000; D++) {
    while ((n + 1) * (n + 1) <= D)
      n++;
    if (n * n < D) {
      int a[SIZE], b[SIZE], c[SIZE];
      a[1] = n;
      b[1] = n;
      c[1] = 1;
      BigInt x[SIZE], y[SIZE];
      x[0] = 1;
      x[1] = n;
      y[0] = 0;
      y[1] = 1;
      for (int i = 2; true; i++) {
        if ((D - b[i - 1] * b[i - 1]) % c[i - 1] != 0)
          cout << "(D - b[i - 1] * b[i - 1]) \% c[i - 1] != 0)" << endl;
        c[i] = (D - b[i - 1] * b[i - 1]) / c[i - 1];
        a[i] = (n + b[i - 1]) / c[i];
        b[i] = a[i] * c[i] - b[i - 1];
        x[i] = x[i - 1] * a[i] + x[i - 2];
        y[i] = y[i - 1] * a[i] + y[i - 2];
        if (i > 2 && i % 2 == 0 && b[i] == b[2] && c[i] == c[2]) {
          if (maximumMinimumX < x[i - 2]) {
            maximumMinimumX = x[i - 2];
            resiredD = D;
          }
          break;
        }
      }
    }
  }
  cout << resiredD << endl;
}
