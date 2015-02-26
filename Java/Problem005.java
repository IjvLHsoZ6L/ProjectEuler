public class Problem005 {

  private static long gcd(long a, long b) {

    while (b > 0) {

      long c = a % b;
      a = b;
      b = c;
    }

    return a;
  }

  private static long lcm(long a, long b) {

    return a * b / gcd(a, b);
  }

  public static void main(String[] args) {

    long m = 1;

    for (long i = 1; i <= 20; i++)
      m = lcm(m, i);

    System.out.println(m);

    return;
  }
}
