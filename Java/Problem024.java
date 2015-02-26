public class Problem024 {

  public static void main(String[] args) {

    int CNT = 1000000;

    int n = CNT - 1;

    int[] align = new int[9 + 1];

    for (int i = 9; i >= 0; i--) {
      align[i] = n % (10 - i) + 1;
      n /= (10 - i);
    }

    int[] perm = new int[9 + 1];

    boolean[] used = new boolean[9 + 1];

    for (int i = 0; i <= 9; i++) {

      for (int j = 0, cnt = 0; cnt < align[i]; j++) {

        if (!used[j])
          cnt++;

        if (cnt == align[i]) {
          perm[i] = j;
          used[j] = true;
        }
      }
    }

    for (int i = 0; i <= 9; i++)
      System.out.print(perm[i]);

    System.out.println();

    return;
  }
}
