public class Problem053 {

  public static void main(String[] args) {

    int[][] combination = new int[100 + 1][100 + 1];
    for (int n = 1; n <= 100; n++) {
      combination[n][0] = 1;
      combination[n][n] = 1;
    }
    for (int n = 2; n <= 100; n++) {
      for (int r = 1; r < n; r++) {
        combination[n][r] = combination[n - 1][r - 1] + combination[n - 1][r];
        if (combination[n][r] > 1000000)
          combination[n][r] = 1000000 + 1;
      }
    }

    int cnt = 0;
    for (int n = 1; n <= 100; n++)
      for (int r = 0; r <= n; r++)
        if (combination[n][r] > 1000000)
          cnt++;

    System.out.println(cnt);

    return;
  }
}
