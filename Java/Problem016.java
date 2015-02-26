public class Problem016 {

  public static void main(String[] args) {

    int INDEX = 1000;
    int[] digit = new int[INDEX];

    digit[0] = 1;

    for (int cnt = 0; cnt < INDEX; cnt++) {

      for (int i = 0; i < INDEX; i++)
        digit[i] *= 2;

      for (int i = 0; i + 1 < INDEX; i++) {
        digit[i + 1] += digit[i] / 10;
        digit[i] %= 10;
      }
    }

    int sum = 0;

    for (int i = 0; i < INDEX; i++)
      sum += digit[i];

    System.out.println(sum);

    return;
  }
}
