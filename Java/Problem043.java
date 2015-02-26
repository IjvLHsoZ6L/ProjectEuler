public class Problem043 {

  public static void main(String[] args) {

    int[] d = new int[10 + 1];
    for (int m = 0; m <= 9; m++) {
      for (int n = 0; n <= 9; n++) {
        if (m != n) {
          d[9] = m;
          d[10] = n;
          sub(9, d);
        }
      }
    }

    long sum = 0;
    for (int i = 0; i < numOfSuchNumbers; i++)
      sum += suchNumbers[i];

    System.out.println(sum);

    return;
  }

  static final int[] divisors = { 0, 1, 2, 3, 5, 7, 11, 13, 17 };

  static int numOfSuchNumbers = 0;

  static long[] suchNumbers = new long[100];

  static void sub(int determined, int[] d) {
    if (determined == 1) {
      if (d[1] > 0) {
        long N = 0;
        for (int i = 1; i <= 10; i++)
          N = 10 * N + d[i];
        numOfSuchNumbers++;
        suchNumbers[numOfSuchNumbers - 1] = N;
      }
    }
    else {
      int[] D = new int[10 + 1];
      boolean[] appear = new boolean[10];
      for (int i = determined; i <= 10; i++) {
        D[i] = d[i];
        appear[d[i]] = true;
      }
      for (int n = 0; n <= 9; n++) {
        if (!appear[n] && (n * 100 + d[determined] * 10 + d[determined + 1]) % divisors[determined - 1] == 0) {
          D[determined - 1] = n;
          sub(determined - 1, D);
        }
      }
    }
    return;
  }
}
