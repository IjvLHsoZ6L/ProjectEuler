public class Problem051 {

  public static void main(String[] args) {

    final int limit = 1000000;
    final int count = 8;

    boolean[] prime = new boolean[limit];
    for (int n = 2; n < limit; n++)
      prime[n] = true;
    for (int n = 2; n * n < limit; n++)
      if (prime[n])
        for (int m = n; m * n < limit; m++)
          prime[m * n] = false;

    /* use 11 as base, and 10 as wild card */
    for (int n = 1; true; n++) {

      if (hasWildCard(n)) {

        int cnt = 0, start = hasWildCardonTop(n) ? 1 : 0;
        for (int d = start; d <= 9; d++)
          if (prime[replace(n, d)])
            cnt++;

        if (cnt == count) {

          int d = hasWildCardonTop(n) ? 1 : 0;
          while (!prime[replace(n, d)])
            d++;

          System.out.println(replace(n, d));

          return;
        }
      }
    }
  }

  static boolean hasWildCard(int n) {
    for (int N = n; N > 0; N /= 11)
      if (N % 11 == 10)
        return true;
    return false;
  }

  static boolean hasWildCardonTop(int n) {
    int m = 0;
    for (int N = n; N > 0; N /= 11)
      m = m * 11 + (N % 11);
    return m % 11 == 10;
  }

  static int replace(int n, int d) {
    int m = 0, k = 0;
    for (int N = n; N > 0; N /= 11)
      m = m * 10 + (N % 11 == 10 ? d : N % 11);
    for (int M = m; M > 0; M /= 10)
      k = k * 10 + (M % 10);
    return k;
  }
}
