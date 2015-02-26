public class Problem025 {

  public static void main(String[] args) {

    int DIGIT = 1000;

    int[] a = new int[DIGIT];
    int[] b = new int[DIGIT];
    int[] c = new int[DIGIT];

    a[0] = 1;
    b[0] = 1;

    int term = 2;

    boolean found = false;

    while (!found) {

      term++;

      for (int i = 0; i < DIGIT; i++)
        c[i] = a[i] + b[i];

      for (int i = 0; i + 1 < DIGIT; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
      }

      if (c[DIGIT - 1] > 0) {

        found = true;
        System.out.println(term);
      }
      else {

        for (int i = 0; i < DIGIT; i++) {
          a[i] = b[i];
          b[i] = c[i];
        }
      }
    }

    return;
  }
}
