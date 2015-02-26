public class Problem012 {

  public static void main(String[] args) {

    int _SUP = 20000;

    int[] numOfDivisor = new int[_SUP];

    for (int i = 1; i < _SUP; i++)
      numOfDivisor[i] = 1;

    for (int p = 2; p < _SUP; p++)
      if (numOfDivisor[p] == 1)
        for (int index = 1, power = p; power < _SUP; index++, power *= p)
          for (int j = 1; j * power  < _SUP; j++)
            numOfDivisor[j * power] = numOfDivisor[j * power] / index * (index + 1);

    boolean found = false;

    for (int n = 1; !found && n + 1 < _SUP; n++) {

      int numOfDivisorOfTri;

      if (n % 2 == 0)

        numOfDivisorOfTri = numOfDivisor[n / 2] * numOfDivisor[n + 1];

      else

        numOfDivisorOfTri = numOfDivisor[n] * numOfDivisor[(n + 1) / 2];

      if (numOfDivisorOfTri > 500) {

        found = true;

        System.out.println(n * (n + 1) / 2);
      }
    }

    return;
  }
}
