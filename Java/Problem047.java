public class Problem047 {

  public static void main(String[] args) {

    int LIMIT = 1000000;

    int[] primeFactos = new int[LIMIT];
    for (int n = 2; n < LIMIT; n++)
      if (primeFactos[n] == 0)
        for (int m = 1; m * n < LIMIT; m++)
          primeFactos[m * n]++;

    int length = 4;

    int consecution = 0;

    for (int n = 1; true; n++) {

      if (primeFactos[n] == length)
        consecution++;
      else
        consecution = 0;

      if (consecution == length) {

        System.out.println(n - length + 1);

        return;
      }
    }
  }
}
