// 0051.cpp
#include <iostream>
using namespace std;

int main() {

    int digit = 6;
    int wildcard = 10;

    int target = 1;
    for ( int i = 0; i < digit; i++ )
        target *= 10;

    bool prime[target];
    prime[0] = prime[1] = false;
    for ( int i = 2; i < target; i++ )
        prime[i] = true;
    for ( int i = 2; i*i < target; i++ )
        if ( prime[i] )
            for ( int j = i; i*j < target; j++ )
                prime[i*j] = false;

    int target2 = 1;
    for ( int i = 0; i < digit; i++ )
        target2 *= 10 + 1;

    for ( int n = 0; n < target2; n++ ) {

        int length = 0;
        int d[digit];
        {
            int N = n;
            while ( N > 0 ) {
                d[length] = N % (10 + 1);
                N /= 10 + 1;
                length++;
            }
        }

        bool exists = false;
        for ( int i = 0; i < length; i++ )
            exists or_eq d[i] == wildcard;

        if ( exists ) {

            int value[10];
            for ( int x = 0; x < 10; x++ ) {
                value[x] = 0;
                for ( int i = length - 1; i >= 0; i-- )
                    value[x] = value[x] * 10 + (d[i] == wildcard ? x : d[i]);
            }

            int cnt = 0;
            for ( int x = 0; x < 10; x++ )
                if ( prime[value[x]] and (x > 0 or d[length - 1] != wildcard) )
                    cnt++;

            if ( cnt == 8 ) {

                int x = 0;
                while ( not prime[value[x]] )
                    x++;

                cout << value[x] << endl;
            }
        }
    }

    return 0;
}
