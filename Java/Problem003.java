public class Problem003 {

  public static void main(String[] args) {

    long N = 600851475143L;

    long n = N;

    int max = 0;

    for (int p = 2; n > 1; p++) {

      while (n % p == 0) {

        n /= p;
        max = p;
      }
    }

    System.out.println(max);

    return;
  }
}
