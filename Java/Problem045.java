public class Problem045 {

  public static void main(String[] args) {

    int first = 1,
        second = 40755,
        T = 1,
        dT = 1,
        ddT = 1,
        P = 1,
        dP = 1,
        ddP = 3,
        H = 1,
        dH = 1,
        ddH = 4;

    while (true) {

      while (P < H) {
        dP += ddP;
        P += dP;
      }

      if (P == H) {

        while (T < P) {
          dT += ddT;
          T += dT;
        }

        if (T == P && T != first && T != second) {

          System.out.println(T);

          return;
        }
      }

      dH += ddH;
      H += dH;
    }
  }
}
