public class Problem002 {

  public static void main(String[] args) {

    int MAX = 4000000;

    int sum = 0;

    int a = 0;
    int b = 1;

    while (a + b <= MAX) {

      if ((a + b) % 2 == 0)
        sum += a + b;

      int c = a + b;
      a = b;
      b = c;
    }

    System.out.println(sum);

    return;
  }
}
