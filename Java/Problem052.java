public class Problem052 {

  public static void main(String[] args) {

    for (int x = 1; true; x++ ) {

      boolean satisfy = true;
      for (int n = 2; satisfy && n <= 6; n++)
        if (!containSameDigits(x, n * x))
          satisfy = false;

      if (satisfy) {
        System.out.println(x);
        return;
      }
    }
  }

  static boolean containSameDigits(int n, int m) {
    int[] difference = new int[10];
    for (int N = n; N > 0; N /= 10)
      difference[N % 10]++;
    for (int M = m; M > 0; M /= 10)
      difference[M % 10]--;
    for (int d = 0; d <= 9; d++)
      if (difference[d] != 0)
        return false;
    return true;
  }
}
