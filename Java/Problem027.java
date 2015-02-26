public class Problem027 {

  public static void main(String[] args) {

    int MAX = 2001000;

    boolean[] prime = new boolean[MAX + 1];
    for (int i = 2; i <= MAX; i++)
      prime[i] = true;
    for (int i = 2; i * i <= MAX; i++)
      if (prime[i])
        for (int j = i; i * j <= MAX; j++)
          prime[i * j] = false;

    int max = 0;
    int product = 0;
    for (int a = -1000; a <= 1000; a++) {
      for (int b = 0; b <= 1000; b++) {
        int n = 0;
        while (n * n + a * n + b >= 0 && prime[n * n + a * n + b])
          n++;
        if (n > max) {
          max = n;
          product = a * b;
        }
      }
    }

    System.out.println(product);

    return;
  }
}
