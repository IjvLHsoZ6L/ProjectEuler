public class Problem028 {

  public static void main(String[] args) {

    int sum = 1;
    int n = 1;

    for (int w = 3; w <= 1001; w += 2) {
      for (int i = 0; i < 4; i++) {
        n += w - 1;
        sum += n;
      }
    }

    System.out.println(sum);

    return;
  }
}
