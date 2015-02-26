public class Problem009 {

  public static void main(String[] args) {

    int SUM = 1000;

    for (int a = 1; a + a + a < SUM; a++) {
      for (int b = a + 1; a + b + b < SUM; b++) {
        int c = SUM - a - b;

        if (a * a + b * b == c * c)
          System.out.println(a * b * c);
      }
    }

    return;
  }
}
