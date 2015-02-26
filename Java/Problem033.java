public class Problem033 {

  public static void main(String[] args) {

    int numerator = 1;
    int denominator = 1;

    for (int a = 1; a <= 9; a++) {
      for (int b = 1; b <= 9; b++) {
        for (int c = a + 1; c <= 9; c++) {
          if ((10 * a + b) * c == a * (10 * b + c)) {
            numerator *= a;
            denominator *= c;
          }
        }
      }
    }

    System.out.println(denominator / gcd(numerator, denominator));

    return;
  }

  static int gcd(int a, int b) {
    while (b > 0) {
      int c = a % b;
      a = b;
      b = c;
    }
    return a;
  }
}
