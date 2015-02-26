public class Problem019 {

  public static void main(String[] args) {

    int[][] numOfDays = new int[2000 + 1][12 + 1];

    for (int y = 1900; y <= 2000; y++) {

      numOfDays[y][1] = 31;

      if (y % 400 == 0)
        numOfDays[y][2] = 29;
      else if (y % 100 == 0)
        numOfDays[y][2] = 28;
      else if (y % 4 == 0)
        numOfDays[y][2] = 29;
      else
        numOfDays[y][2] = 28;

      numOfDays[y][3] = 31;
      numOfDays[y][4] = 30;
      numOfDays[y][5] = 31;
      numOfDays[y][6] = 30;
      numOfDays[y][7] = 31;
      numOfDays[y][8] = 31;
      numOfDays[y][9] = 30;
      numOfDays[y][10] = 31;
      numOfDays[y][11] = 30;
      numOfDays[y][12] = 31;
    }

    int cnt = 0;

    int day = 1;

    for (int y = 1900; y <= 2000; y++) {
      for (int m = 1; m <= 12; m++) {

        if (y >= 1901 && day == 0)
          cnt++;

        day += numOfDays[y][m];
        day %= 7;
      }
    }

    System.out.println(cnt);

    return;
  }
}
