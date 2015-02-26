public class Problem014 {

  private static long next(long n) {

    if (n % 2 == 0)

      return n / 2;

    else

      return 3 * n + 1;
  }

  public static void main(String[] args) {

    int SUP = 1000000;

    int[] collatzLength = new int[SUP];

    collatzLength[1] = 1;

    for (int n = 2; n < SUP; n++) {

      long m = (long) n;
      int length = 1;

      while (!(m < SUP) || collatzLength[(int) m] == 0) {

        m = next(m);
        length++;
      }

      length += collatzLength[(int) m];

      m = (long) n;

      while (!(m < SUP) || collatzLength[(int) m] == 0) {

        if (m < SUP)
          collatzLength[(int) m] = length;

        m = next(m);
        length--;
      }
    }

    int max = 0;

    for (int n = 0; n < SUP; n++)
      if (collatzLength[n] > max)
        max = collatzLength[n];

    for (int n = 0; n < SUP; n++)
      if(collatzLength[n] == max)
        System.out.println(n);

    return;
  }
}
