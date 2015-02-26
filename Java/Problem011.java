import java.io.*;

public class Problem011 {

  public static void main(String[] args) throws IOException {

    int SIZE = 20;

    int[][] array = new int[SIZE][SIZE];

    StreamTokenizer st = new StreamTokenizer(new FileReader("Problem011.txt"));

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        st.nextToken();
        array[i][j] = (int) st.nval;
      }
    }

    int max = 0;

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j + 3 < SIZE; j++) {

        int prod = 1;

        for (int k = 0; k < 4; k++)
          prod *= array[i][j + k];

        if (prod > max)
          max = prod;
      }
    }

    for (int i = 0; i + 3 < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {

        int prod = 1;

        for (int k = 0; k < 4; k++)
          prod *= array[i + k][j];

        if (prod > max)
          max = prod;
      }
    }

    for (int i = 0; i + 3 < SIZE; i++) {
      for (int j = 0; j + 3 < SIZE; j++) {

        int prod = 1;

        for (int k = 0; k < 4; k++)
          prod *= array[i + k][j + k];

        if (prod > max)
          max = prod;
      }
    }

    for (int i = 0; i + 3 < SIZE; i++) {
      for (int j = 0; j + 3 < SIZE; j++) {

        int prod = 1;

        for (int k = 0; k < 4; k++)
          prod *= array[i + k][j + 3 - k];

        if (prod > max)
          max = prod;
      }
    }

    System.out.println(max);

    return;
  }
}
