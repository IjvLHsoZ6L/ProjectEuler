import java.io.*;

public class Problem022 {

  private static boolean ordered(String s, String t) {

    int i = 0;

    while (i < s.length() && i < t.length() && s.charAt(i) == t.charAt(i))
      i++;

    if (i < s.length() && i < t.length())

      return s.charAt(i) < t.charAt(i);

    else

      return s.length() < t.length();
  }

  private static void quicksort(String[] name, int start, int end) {

    if (start == end)

      return;

    else {

      String pivot = name[start];

      int i = start;
      int j = end;

      while (i <= j) {

        while (i <= end && ordered(name[i], pivot))
          i++;

        while (j >= start && !ordered(name[j], pivot))
          j--;

        if (i < j) {

          String temp = name[i];
          name[i] = name[j];
          name[j] = temp;

          i++;
          j--;
        }
      }

      if (start < j)
        quicksort(name, start, j);

      if (i < end)
        if (i == start)
          quicksort(name, start + 1, end);
        else
          quicksort(name, i, end);

      return;
    }
  }

  public static void main(String[] args) throws IOException {

    int numOfName = 0;

    String[] name = new String[10000];

    StreamTokenizer st = new StreamTokenizer(new FileReader("Problem022.txt"));
    st.resetSyntax();
    st.wordChars('A', 'Z');

    while (st.nextToken() != st.TT_EOF) {
      if (st.ttype == st.TT_WORD) {

        name[numOfName] = st.sval;
        numOfName++;
      }
    }

    quicksort(name, 0, numOfName - 1);

    int sumOfScore = 0;

    for (int i = 0; i < numOfName; i++) {

      int score = 0;

      for (int j = 0; j < name[i].length(); j++)
        score += name[i].charAt(j) - 'A' + 1;

      sumOfScore += (i + 1) * score;
    }

    System.out.println(sumOfScore);

    return;
  }
}
