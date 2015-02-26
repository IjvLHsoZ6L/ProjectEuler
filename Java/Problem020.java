public class Problem020 {

  public static void main(String[] args) {

    int _DIGIT = 200;

    int[] digit = new int[_DIGIT];

    digit[0] = 1;

    for (int n = 1; n <= 100; n++) {

      for (int i = 0; i < _DIGIT; i++)
        digit[i] *= n;

      for (int i = 0; i + 1 < _DIGIT; i++) {
        digit[i + 1] += digit[i] / 10;
        digit[i] %= 10;
      }
    }

    int sum = 0;

    for (int i = 0; i < _DIGIT; i++)
      sum += digit[i];

    System.out.println(sum);

    return;
  }
}
