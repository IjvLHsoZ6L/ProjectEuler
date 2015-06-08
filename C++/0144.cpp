#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int count = 0;
    double vx = 1.4 - 0.0;
    double vy = -9.6 - 10.1;
    double px = 1.4;
    double py = -9.6;
    double a, b, c, vx_temp, vy_temp, t;
    while (true) {
        if (py > 0 and -0.01 <= px and px <= 0.01)
            break;
        count++;
        a = 16 * px * px + py * py;
        b = 16 * px * px - py * py;
        c = 8 * px * py;
        vx_temp = (- b * vx - c * vy) / a;
        vy_temp = (- c * vx + b * vy) / a;
        vx = vx_temp;
        vy = vy_temp;
        t = -2 * (4 * px * vx + py * vy) / (4 * vx * vx + vy * vy);
        px += vx * t;
        py += vy * t;
    }

    cout << count << endl;

    return 0;
}
