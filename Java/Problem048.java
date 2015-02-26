public class Problem048 {

  public static void main(String[] args) {

    int DIGITS = 10;

    int[] sum = new int[DIGITS];

    int MAX = 1000;

    for (int n = 1; n <= MAX; n++) {

      int[] powor = new int[DIGITS];

      powor[0] = 1;

      for (int cnt = 0; cnt < n; cnt++) {

        for (int i = 0; i < DIGITS; i++)
          powor[i] *= n;

        for (int i = 0, temp = 0; i < DIGITS; i++) {
          powor[i] += temp;
          temp = powor[i] / 10;
          powor[i] %= 10;
        }
      }

      for (int i = 0; i < DIGITS; i++)
        sum[i] += powor[i];

      for (int i = 0, temp = 0; i < DIGITS; i++) {
        sum[i] += temp;
        temp = sum[i] / 10;
        sum[i] %= 10;
      }
    }

    for (int i = DIGITS - 1; i >= 0; i--)
      System.out.print(sum[i]);

    System.out.println();

    return;
  }
}
