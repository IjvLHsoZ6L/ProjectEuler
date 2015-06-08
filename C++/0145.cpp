#include <iostream>

using namespace std;

int main() {

    const int less              = 5;
    const int odd_less          = 30;
    const int odd_less_nonzero  = 20;
    const int odd_greater       = 20;
    const int even_less         = 25;

    int count = 0;
    for (int digit = 1; digit <= 9; digit++) {
        int product;
        switch (digit % 4) {
            case 0:
            case 2:
                product = odd_less_nonzero;
                for (int i = 1; i < digit / 2; i++)
                    product *= odd_less;
                break;
            case 1:
                product = 0;
                break;
            case 3:
                product = odd_greater * less;
                for (int i = 0; i < (digit - 3) / 4; i++)
                    product *= even_less * odd_greater;
                break;
        }
        count += product;
    }

    cout << count << endl;

    return 0;
}
