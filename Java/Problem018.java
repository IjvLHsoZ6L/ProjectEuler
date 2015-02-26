import java.io.*;

public class Problem018 {

  private static int max(int a, int b) {

    if (a < b)

      return b;

    else

      return a;
  }

  public static void main(String[] args) throws IOException {

    int SIZE = 15;

    int[][] tri = new int[SIZE][SIZE];

    StreamTokenizer st = new StreamTokenizer(new FileReader("Problem018.txt"));

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j <= i; j++) {
        st.nextToken();
        tri[i][j] = (int) st.nval;
      }
    }

    for (int i = SIZE - 2; !(i < 0); i--)
      for (int j = 0; j <= i; j++)
        tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);

    System.out.println(tri[0][0]);

    return;
  }
}
