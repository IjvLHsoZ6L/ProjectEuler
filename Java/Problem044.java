public class Problem044 {

  public static void main(String[] args) {

    int LIMIT = 10000000;

    boolean[] pentagonal = new boolean[LIMIT];

    for (int P = 1, dP = 4; P < LIMIT; P += dP, dP += 3)
      pentagonal[P] = true;

    boolean found = false;

    for (int P1 = 1, dP1 = 4; !found && P1 < LIMIT; P1 += dP1, dP1 += 3) {
      for (int P2 = 1, dP2 = 4; !found && dP2 <= P1 && P1 + P2 + P2 < LIMIT; P2 += dP2, dP2 += 3) {
        if (pentagonal[P1 + P2] && pentagonal[P1 + P2 + P2]) {
          System.out.println(P1);
          found = true;
        }
      }
    }

    return;
  }
}
