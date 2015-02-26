import java.io.*;

public class Problem042 {

  public static void main(String[] args) throws IOException {

    int cnt = 0;

    StreamTokenizer st = new StreamTokenizer(new FileReader("Problem042.txt"));

    st.resetSyntax();
    st.wordChars('A', 'Z');

    while (st.nextToken() != st.TT_EOF) {
      if (st.ttype == st.TT_WORD) {
        int value = 0;
        for (int i = 0; i < st.sval.length(); i++)
          value += st.sval.charAt(i) - 'A' + 1;
        if (triangle(value))
          cnt++;
      }
    }

    System.out.println(cnt);

    return;
  }

  static boolean triangle(int n) {
    int length = 0;
    int triangle = 0;
    while (triangle < n) {
      length++;
      triangle += length;
    }
    return triangle == n;
  }
}
