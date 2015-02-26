public class Problem046 {

  public static void main(String[] args) {

    int LIMIT = 10000;

    boolean[] prime = new boolean[LIMIT];
    for (int n = 2; n < LIMIT; n++)
      prime[n] = true;
    for (int n = 2; n * n < LIMIT; n++)
      if (prime[n])
        for (int m = n; m * n < LIMIT; m++)
          prime[m * n] = false;

    for (int n = 9; true; n++) {

      if (!prime[n] && n % 2 == 1) {

        boolean found = false;

        for (int m = 0; !found && 2 * m * m < n; m++)
          if (prime[n - 2 * m * m])
            found = true;

        if (!found) {

          System.out.println(n);

          return;
        }
      }
    }
  }
}
