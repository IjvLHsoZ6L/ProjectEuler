public class Problem036 {

  public static void main(String[] args) {

    int LIMIT = 1000000;

    int sum = 0;

    for (int n = 1; n < LIMIT; n++)
      if (palindromic(n, 10) && palindromic(n, 2))
        sum += n;

    System.out.println(sum);

    return;
  }

  static boolean palindromic(int n, int base) {
    int length = 0;
    int[] digits = new int[20];
    for (int N = n; N > 0; N /= base) {
      length++;
      digits[length - 1] = N % base;
    }
    boolean palindromic = true;
    for (int i = 0; palindromic && i < length - i - 1; i++)
      palindromic = palindromic && digits[i] == digits[length - i - 1];
    return palindromic;
  }
}
