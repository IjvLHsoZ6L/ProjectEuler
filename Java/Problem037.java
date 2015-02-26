public class Problem037 {

  public static void main(String[] args) {

    computePrime();

    int sum = 0;

    for (int cnt = 0, n = 10; cnt < 11; n++) {
      boolean truncable = prime[n];
      for (int N = leftTruncate(n); truncable && N > 0; N = leftTruncate(N))
        truncable = truncable && prime[N];
      for (int N = rightTruncate(n); truncable && N > 0; N = rightTruncate(N))
        truncable = truncable && prime[N];
      if (truncable) {
        sum += n;
        cnt++;
      }
    }

    System.out.println(sum);

    return;
  }

  static int LIMIT = 1000000;

  static boolean[] prime;

  static void computePrime() {
    prime = new boolean[LIMIT];
    for (int n = 2; n < LIMIT; n++)
      prime[n] = true;
    for (int n = 2; n * n < LIMIT; n++)
      if (prime[n])
        for (int m = n; m * n < LIMIT; m++)
          prime[m * n] = false;
    return;
  }

  static int leftTruncate(int n) {
    int unit = 1;
    while (!(10 * unit > n))
      unit *= 10;
    return n % unit;
  }

  static int rightTruncate(int n) {
    return n / 10;
  }
}
