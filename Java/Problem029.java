public class Problem029 {

  public static void main(String args[]) {

    boolean[][] unique = new boolean[100 + 1][100 + 1];

    for (int a = 2; a <= 100; a++)
      for (int b = 2; b <= 100; b++)
        unique[a][b] = true;

    for (int a = 2; a <= 100; a++)
      for (int b = 2; b <= 100; b++)
        for (int m = 1, am = a; am <= 100 && m * b <= 100; m++, am *= a)
          for (int n = m + 1, an = am * a; an <= 100 && n * b <= 100; n++, an *= a)
            unique[an][m * b] = false;

    int cnt = 0;
    for (int a = 2; a <= 100; a++)
      for (int b = 2; b <= 100; b++)
        if (unique[a][b])
          cnt++;

    System.out.println(cnt);

    return;
  }
}
