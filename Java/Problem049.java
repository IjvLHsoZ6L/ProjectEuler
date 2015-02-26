public class Problem049 {

  public static void main(String[] args) {

    boolean[] prime = new boolean[9999 + 1];
    for (int n = 2; n <= 9999; n++)
      prime[n] = true;
    for (int n = 2; n * n <= 9999; n++)
      if (prime[n])
        for (int m = n; m * n <= 9999; m++)
          prime[m * n] = false;

    for (int n = 1000; n <= 9999; n++) {

      if (prime[n]) {

        for (int d = 1; n + d + d <= 9999; d++) {

          if (prime[n + d] && prime[n + d + d] &&
              permutation(n, n + d) && permutation(n, n + d + d) &&
              !(n == 1487 && d == 3330))
          {
            System.out.print(n);
            System.out.print(n + d);
            System.out.print(n + d + d);
            System.out.println();

            return;
          }
        }
      }
    }
  }

  static boolean permutation(int n, int m) {

    int[] diff = new int[10];

    for (int N = n; N > 0; N /= 10)
      diff[N % 10]++;

    for (int M = m; M > 0; M /= 10)
      diff[M % 10]--;

    boolean zero = true;

    for (int d = 0; zero && d < 10; d++)
      zero = diff[d] == 0;

    return zero;
  }
}
