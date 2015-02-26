public class Problem026 {

  public static void main(String[] args) {

    int lengthLongest = 0;
    int dLongest = 0;

    for (int d = 2; d < 1000; d++) {

      int[] appeared = new int[d];

      int length;

      for (int i = 1, r = 1; true; i++, r = (10 * r) % d) {

        if (r == 0) {
          length = 0;
          break;
        }
        else if (appeared[r] > 0) {
          length = i - appeared[r];
          break;
        }

        appeared[r] = i;
      }

      if (length > lengthLongest) {
        lengthLongest = length;
        dLongest = d;
      }
    }

    System.out.println(dLongest);

    return;
  }
}
