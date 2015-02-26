public class Problem021 {

  public static void main(String[] args) {

    int MAX = 10000;

    int[] sumOfDivisors = new int[MAX];

    for (int n = 1; n < MAX; n++)
      sumOfDivisors[n] = 1;

    for (int p = 2; p < MAX; p++)
      if (sumOfDivisors[p] == 1)
        for (int power = p, sumOfPower = 1 + p; power < MAX; power *= p, sumOfPower += power)
          for (int i = 1; i * power < MAX; i++)
            sumOfDivisors[i * power] = sumOfDivisors[i * power] / (sumOfPower - power) * sumOfPower;

    for (int n = 1; n < MAX; n++)
      sumOfDivisors[n] -= n;

    int sum = 0;

    for (int n = 1; n < MAX; n++)
      if (sumOfDivisors[n] < MAX && sumOfDivisors[n] != n && sumOfDivisors[sumOfDivisors[n]] == n)
        sum += n;

    System.out.println(sum);

    return;
  }
}
