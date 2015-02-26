public class Problem015 {

  public static void main(String[] args) {

    int SIZE = 20;

    long[][] numOfRoute = new long[SIZE + 1][SIZE + 1];

    for (int i = 1; i <= SIZE; i++)
      numOfRoute[i][0] = numOfRoute[0][i] = 1L;

    for (int i = 1; i <= SIZE; i++)
      for (int j = 1; j <= SIZE; j++)
        numOfRoute[i][j] = numOfRoute[i - 1][j] + numOfRoute[i][j - 1];

    System.out.println(numOfRoute[SIZE][SIZE]);

    return;
  }
}
