public class Problem041 {

  public static void main(String[] args) {

    computePrimes();

    int n = MAX;

    while (!(prime[n] && pandigital(n)))
      n--;

    System.out.println(n);

    return;
  }

  static int MAX = 7654321;

  static boolean[] prime;

  static void computePrimes() {
    prime = new boolean[MAX + 1];
    for (int n = 2; n <= MAX; n++)
      prime[n] = true;
    for (int n = 2; n * n <= MAX; n++)
      if (prime[n])
        for (int m = n; m * n <= MAX; m++)
          prime[m * n] = false;
    return;
  }

  static boolean pandigital(int n) {
    int[] appear = new int[10];
    for (int N = n; N > 0; N /= 10)
      appear[N % 10]++;
    int d = 1;
    while (d <= 9 && appear[d] == 1)
      d++;
    boolean pandigital = appear[0] == 0;
    while (pandigital && d <= 9) {
      pandigital = pandigital && appear[d] == 0;
      d++;
    }
    return pandigital;
  }
}
