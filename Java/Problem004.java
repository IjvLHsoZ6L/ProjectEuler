public class Problem004 {

  private static int _DIGIT = 6;

  private static boolean palindromic(int n) {

    int[] digit = new int[_DIGIT];

    int length = 0;

    while (n > 0) {

      digit[length] = n % 10;
      n /= 10;
      length++;
    }

    boolean b = true;

    for (int i = 0; i < length / 2; i++)
      b = b && digit[i] == digit[length - 1 - i];

    return b;
  }

  public static void main(String[] args) {

    int max = 0;

    for (int a = 100; a <= 999; a++)
      for (int b = a; b <= 999; b++)
        if (palindromic(a * b) && a * b > max)
          max = a * b;

    System.out.println(max);

    return;
  }
}
