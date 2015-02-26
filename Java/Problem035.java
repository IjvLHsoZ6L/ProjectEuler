public class Problem035 {

  public static void main(String[] args) {

    calcPrimes();

    int numOfCircularPrimes = 0;

    for (int n = 1; n < LIMIT; n++) {
      boolean circular = true;
      for (int cnt = 0, N = n; circular && cnt < numOfDigit(n); cnt++, N = cycle(N))
        circular = circular && prime[N];
      if (circular)
        numOfCircularPrimes++;
    }

    System.out.println(numOfCircularPrimes);

    return;
  }

  static int LIMIT = 1000000;

  static boolean[] prime;

  static void calcPrimes() {
    prime = new boolean[LIMIT];
    for (int n = 2; n < LIMIT; n++)
      prime[n] = true;
    for (int n = 2; n * n < LIMIT; n++)
      if (prime[n])
        for (int m = n; m * n < LIMIT; m++)
          prime[m * n] = false;
    return;
  }

  static int numOfDigit(int n) {
    int cnt = 0;
    for (int N = n; N > 0; N /= 10)
      cnt++;
    return cnt;
  }

  static int cycle(int n) {
    int unit = 1;
    while (!(10 * unit > n))
      unit *= 10;
    return n % 10 * unit + n / 10;
  }
}
