// 0017.cpp
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    // one, two, three, four, five, six, seven, eight, nine
    sum += (3+3+5+4+4+3+5+5+4)*(9*10 + 100);
    // ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    sum += (3+6+6+8+8+7+7+9+8+8)*10;
    // twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
    sum += (6+6+5+5+5+7+6+6)*10*10;
    // hundred
    sum += 7*100*9;
    // and
    sum += 3*99*9;
    // one thousand
    sum += 3 + 8;

    cout << sum << endl;

    return 0;
}
