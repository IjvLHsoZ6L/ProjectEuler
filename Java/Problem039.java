public class Problem039 {

  public static void main(String[] args) {

    int MAX = 1000;

    int[] numOfSolutions = new int[MAX + 1];

    for (int a = 1; a + a + a <= MAX; a++) {
      int c = a;
      for (int b = a; a + b + c <= MAX; b++) {
        while (c * c < a * a + b * b)
          c++;
        if (a * a + b * b == c * c && a + b + c <= MAX)
          numOfSolutions[a + b + c]++;
      }
    }

    int max = 0;
    int pGivesMax = 0;
    for (int p = 1; p <= MAX; p++) {
      if (numOfSolutions[p] > max) {
        max = numOfSolutions[p];
        pGivesMax = p;
      }
    }

    System.out.println(pGivesMax);

    return;
  }
}
