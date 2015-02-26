public class Problem017 {

  public static void main(String[] args) {

    int sum = 0;

    // one
    sum += 3 * (90 + 100 + 1);

    // two, three, four, five, six, seven, eight, nine
    sum += (3 + 5 + 4 + 4 + 3 + 5 + 5 + 4) * (90 + 100);

    // ten
    sum += 3 * 10;

    // eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    sum += (6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8) * 10;

    // twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
    sum += (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) * 100;

    // hundred
    sum += 7 * 900;

    // and
    sum += 3 * (99 * 9);

    // thousand
    sum += 8;

    System.out.println(sum);

    return;
  }
}
