import java.io.*;

public class Problem008 {

  public static void main(String[] args) throws IOException {

    int LENGTH = 1000;

    int[] seq = new int[LENGTH];

    FileReader fr = new FileReader("Problem008.txt");

    for (int i = 0; i < LENGTH; i++)
      seq[i] = fr.read() - '0';

    int max = 0;

    for (int i = 0; i + 4 < LENGTH; i++) {

      int prod = 1;

      for (int j = 0; j < 5; j++)
        prod *= seq[i + j];

      if (prod > max)
        max = prod;
    }

    System.out.println(max);

    return;
  }
}
