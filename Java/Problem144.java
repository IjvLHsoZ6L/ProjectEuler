public class Problem144 {

  public static void main(String[] args) {

    int count = 0;
    double previousX = 0.0;
    double previousY = 10.1;
    double currentX = 1.4;
    double currentY = -9.6;
    double inX = currentX - previousX;
    double inY = currentY - previousY;

    while (true) {

      if (Math.abs(currentX) <= 0.01 && currentY > 0)
        break;

      double a =
        (4 * currentX * inX + currentY * inY) /
        (16 * currentX * currentX + currentY * currentY);

      double outX = inX - 2 * a * 4 * currentX;
      double outY = inY - 2 * a * currentY;

      double t =
        (8 * currentX * outX + 2 * currentY * outY) /
        (4 * outX * outX + outY * outY);
      double nextX = currentX - t * outX;
      double nextY = currentY - t * outY;

      previousX = currentX;
      previousY = currentY;
      currentX = nextX;
      currentY = nextY;
      inX = currentX - previousX;
      inY = currentY - previousY;

      count++;
    }

    System.out.println(count);
  }
}
