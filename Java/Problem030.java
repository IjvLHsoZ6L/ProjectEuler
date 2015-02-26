public class Problem030 {

  public static void main(String[] args) {

    int LIMIT = 1000000;

    int[] sumOfFifthPower = new int[LIMIT];

    for (int d = 0; d <= 9; d++) {

      int power = 1;
      for (int cnt = 0; cnt < 5; cnt++)
        power *= d;

      for (int ten = 1; 10 * ten <= LIMIT; ten *= 10)
        for (int n = 0; n < ten; n++)
          for (int m = 0; 10 * m * ten < LIMIT; m++)
            sumOfFifthPower[(10 * m + d) * ten + n] += power;
    }

    int sum = 0;

    for (int n = 2; n < LIMIT; n++)
      if (sumOfFifthPower[n] == n)
        sum += n;

    System.out.println(sum);

    return;
  }
}
