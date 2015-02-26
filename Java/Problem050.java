public class Problem050 {

  public static void main(String[] args) {

    int LIMIT = 1000000;

    boolean[] prime = new boolean[LIMIT];
    for (int n = 2; n < LIMIT; n++)
      prime[n] = true;
    for (int n = 2; n * n < LIMIT; n++)
      if (prime[n])
        for (int m = n; m * n < LIMIT; m++)
          prime[m * n] = false;

    int[] p = new int[LIMIT];
    int primes = 0;
    for (int n = 2; n < LIMIT; n++)
      if (prime[n])
        p[primes++] = n;

    int maxLength = 0,
        longestSum = 0;
    for (int i = 0; i < primes; i++) {
      for (int length = 1, sum = p[i]; sum < LIMIT && i + length - 1 < primes; sum += p[i + length++]) {
        if (prime[sum] && length > maxLength) {
          maxLength = length;
          longestSum = sum;
        }
      }
    }

    System.out.println(longestSum);
    return;
  }
}
