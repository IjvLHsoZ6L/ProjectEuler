#include <iostream>
using namespace std;

int main() {

  int const LIMIT = 120000;
  bool isSum[LIMIT + 1];
  for (int i = 0; i <= LIMIT; i++)
    isSum[i] = false;

  for (long long p = 1; p + p + p <= LIMIT; p++) {
    long long a = p;
    for (long long q = p + 1; p + q + q <= LIMIT; q++) {
      while (a * a < p * p + p * q + q * q)
        a++;
      if (a * a == p * p + p * q + q * q) {
        long long b = q;
        long long c = q;
        for (long long r = q + 1; p + q + r <= LIMIT; r++) {
          while (b * b < p * p + p * r + r * r)
            b++;
          if (b * b == p * p + p * r + r * r) {
            while (c * c < q * q + q * r + r * r)
              c++;
            if (c * c == q * q + q * r + r * r) {
              //cout << p + q + r << endl;
              isSum[p + q + r] = true;
            }
          }
        }
      }
    }
  }

  long long sum = 0;
  for (int i = 0; i <= LIMIT; i++)
    if (isSum[i])
      sum += i;

  cout << sum << endl;
}
