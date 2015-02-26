public class Problem032 {

  public static void main(String[] args) {

    boolean[] beProduct = new boolean[10000];

    for (int multiplicand = 1; inRange(multiplicand, multiplicand); multiplicand++)
      for (int multiplier = multiplicand; inRange(multiplicand, multiplier); multiplier++)
        if (satisfyCondition(multiplicand, multiplier))
          beProduct[multiplicand * multiplier] = true;

    int sum = 0;

    for (int product = 0; product < beProduct.length; product++)
      if (beProduct[product])
        sum += product;

    System.out.println(sum);

    return;
  }

  static int numOfDigit(int n) {
    int numOfDigit = 0;
    for (int N = n; N > 0; N /= 10)
      numOfDigit++;
    return numOfDigit;
  }

  static int[] digitAppear(int n) {
    int[] appear = new int[10];
    for (int N = n; N > 0; N /= 10)
      appear[N % 10]++;
    return appear;
  }

  static void add(int[] a, int[] b) {
    for (int d = 0; d <= 9; d++)
      a[d] += b[d];
    return;
  }

  static boolean pandigital(int[] a) {
    boolean pandigital = a[0] == 0;
    for (int d = 1; pandigital && d <= 9; d++)
      pandigital = pandigital && a[d] == 1;
    return pandigital;
  }

  static boolean inRange(int multiplicand, int multiplier) {
    int product = multiplicand * multiplier;
    return numOfDigit(multiplicand) + numOfDigit(multiplier) + numOfDigit(product) <= 9;
  }

  static boolean satisfyCondition(int multiplicand, int multiplier) {
    int product = multiplicand * multiplier;
    int[] a = new int[10];
    add(a, digitAppear(multiplicand));
    add(a, digitAppear(multiplier));
    add(a, digitAppear(product));
    return pandigital(a);
  }
}
