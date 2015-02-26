public class Problem040 {

  public static void main(String[] args) {

    int MAX = 1000000;
    int product = 1;

    for (int length = 0, next = 1, powerOfTen = 1, numOfDigits = 1;
        next <= MAX;
        length += 9 * powerOfTen * numOfDigits, powerOfTen *= 10, numOfDigits++)
    {
      for ( ; next <= length + 9 * powerOfTen * numOfDigits && next <= MAX; next *= 10) {
        int n = (next - length - 1) / numOfDigits + powerOfTen;
        int i = numOfDigits - 1 - (next - length - 1) % numOfDigits;
        product *= getDigit(n, i);
      }
    }

    System.out.println(product);

    return;
  }

  static int getDigit(int n, int i) {
    int N = n;
    for (int cnt = 0; cnt < i; cnt++)
      N /= 10;
    return N % 10;
  }
}
