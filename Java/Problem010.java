public class Problem010 {

  public static void main(String[] args) {

    int SUP = 2000000;

    boolean[] prime = new boolean[SUP];

    for (int i = 2; i < SUP; i++)
      prime[i] = true;

    for (int i = 2; i * i < SUP; i++)
      if (prime[i])
        for (int j = i; i * j < SUP; j++)
          prime[i * j] = false;

    long sum = 0;

    for (int p = 0; p < SUP; p++)
      if (prime[p])
        sum += p;

    System.out.println(sum);

    return;
  }
}
