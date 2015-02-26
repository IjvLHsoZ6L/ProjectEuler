import java.io.*;

public class Problem013 {

  public static void main(String[] args) throws IOException {

    FileReader fr = new FileReader("Problem013.txt");

    int[][] array = new int[100][50];

    for (int i = 0; i < 100; i++) {

      for (int j = 0; j < 50; j++)
        array[i][49 - j] = fr.read() - '0';

      fr.read();
    }

    for (int i = 1; i < 100; i++) {

      for (int j = 0; j < 50; j++)
        array[i][j] += array[i - 1][j];

      for (int j = 0; j + 1 < 50; j++) {
        array[i][j + 1] += array[i][j] / 10;
        array[i][j] %= 10;
      }
    }

    int length = 0;

    for (int power = 1; power <= array[99][49]; power *= 10)
      length++;

    System.out.print(array[99][49]);

    for (int j = 48; length < 10; j--, length++)
      System.out.print(array[99][j]);

    System.out.println();

    return;
  }
}
