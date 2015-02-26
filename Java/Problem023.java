public class Problem023 {

  public static void main(String[] args) {

    int SUP = 28123;

    int[] sumOfDiv = new int[SUP];

    for (int n = 1; n < SUP; n++)
      sumOfDiv[n] = 1;

    for (int p = 2; p < SUP; p++)
      if (sumOfDiv[p] == 1)
        for (int power = p, sumOfPow = 1 + p; power < SUP; power *= p, sumOfPow += power)
          for (int k = 1; k * power < SUP; k++)
            sumOfDiv[k * power] = sumOfDiv[k * power] / (sumOfPow - power) * sumOfPow;

    for (int n = 1; n < SUP; n++)
      sumOfDiv[n] -= n;

    boolean[] sumOfAbd = new boolean[SUP];

    for (int m = 1; m + m < SUP; m++)
      if (sumOfDiv[m] > m)
        for (int n = m; m + n < SUP; n++)
          if (sumOfDiv[n] > n)
            sumOfAbd[m + n] = true;

    int sum = 0;

    for (int n = 1; n < SUP; n++)
      if (!sumOfAbd[n])
        sum += n;

    System.out.println(sum);

    return;
  }
}
