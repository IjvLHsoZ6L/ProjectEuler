public class Problem031 {

  public static void main(String[] args) {

    int[] valueOfCoin = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int numOfCoin = valueOfCoin.length;

    int value = 200;

    int[][] numOfWays = new int[numOfCoin][value + 1];

    numOfWays[0][0] = 1;
    for (int i = 0; i < numOfCoin; i++) {
      for (int n = 0; n <= value; n++) {
        if (i > 0)
          numOfWays[i][n] += numOfWays[i - 1][n];
        if (n >= valueOfCoin[i])
          numOfWays[i][n] += numOfWays[i][n - valueOfCoin[i]];
      }
    }

    System.out.println(numOfWays[numOfCoin - 1][value]);

    return;
  }
}
