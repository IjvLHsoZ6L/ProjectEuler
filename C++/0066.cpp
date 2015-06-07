#include <iostream>
#include <utility>

using namespace std;

int main() {

    int D_max = -1;
    double x_max = -1;

    for (int D = 0, r = 0; D <= 1000; D++) {

        while ((r + 1) * (r + 1) <= D)
            r++;
        if (D == r * r)
            continue;

        int a = D;
        int b = 0;
        int a_prev, b_prev;
        int c;
        double matrix[2][2] = {{1, 0}, {0, 1}};
        while (true) {
            for (int count = 0; count < 2; count++) {
                a_prev = a;
                b_prev = b;
                a = (D - b_prev * b_prev) / a_prev;
                if ((D - b_prev * b_prev) % a_prev != 0) {
                    cout << "somthing wrong!" << endl;
                    return 1;
                }
                b = r - (r + b_prev) % a;
                c = (r + b_prev) / a;
                for (int i = 0; i < 2; i++) {
                    swap(matrix[i][0], matrix[i][1]);
                    matrix[i][1] += c * matrix[i][0];
                }
            }
            if (a == D - r * r and b == r) {
                double x = matrix[1][1];
                if (x > x_max) {
                    x_max = x;
                    D_max = D;
                }
                break;
            }
        }
    }

    cout << D_max << endl;

    return 0;
}
