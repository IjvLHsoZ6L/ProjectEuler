public class Problem007 {

  public static void main(String[] args) {

    int CNT = 10001;

    boolean prime[] = new boolean[1000000];

    for (int i = 2; i < prime.length; i++)
      prime[i] = true;

    for (int i = 2; i * i < prime.length; i++)
      if (prime[i])
        for (int j = i; i * j < prime.length; j++)
          prime[i * j] = false;

    for(int p = 0, cnt = 0; p < prime.length && cnt < CNT; p++) {

      if (prime[p])
        cnt++;

      if (cnt == CNT)
        System.out.println(p);
    }

    return;
  }
}
