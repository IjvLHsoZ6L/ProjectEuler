public class Problem038 {

  public static void main(String[] args) {

    int max = 0;

    for (int m = 1; m <= 9999; m++) {

      int length = 0;
      int[] digits = new int[20];
      int[] appear = new int[10];
      for (int n = 1; length < 9; n++) {
        int tempLength = 0;
        int[] tempDigit = new int[20];
        for (int N = m * n; N > 0; N /= 10) {
          tempLength++;
          tempDigit[tempLength - 1] = N % 10;
          appear[N % 10]++;
        }
        length += tempLength;
        for (int i = 0; i < tempLength; i++)
          digits[length - i - 1] = tempDigit[i];
      }

      if (length == 9) {

        boolean pandromic = appear[0] == 0;
        for (int d = 1; pandromic && d <= 9; d++)
          pandromic = pandromic && appear[d] == 1;

        if (pandromic) {
          int p = 0;
          for (int i = 0; i < 9; i++)
            p = p * 10 + digits[i];
          if (p > max)
            max = p;
        }
      }
    }

    System.out.println(max);

    return;
  }
}
