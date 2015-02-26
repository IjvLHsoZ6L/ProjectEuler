// 085.cpp
#include <iostream>
using namespace std;

int main() {

    int target = 2e6;

    bool stop = false;
    int min = target;
    int height0 = 0, width0 = 0;
    for ( int height = 2; not stop; height++ ) {

        int prev = 0;
        bool over = false;
        for ( int width = height; not over; width++ ) {


            int cnt = 0;
            for ( int h = 1; h <= height; h++ )
                for ( int w = 1; w <= width; w++ )
                    cnt += (height - h + 1) * (width - w + 1);

            if ( cnt < target )
                prev = cnt;

            else {
                over = true;

                if ( target - prev < min ) {
                        min = target - prev;
                        height0 = height;
                        width0 = width - 1;
                }

                if ( cnt - target < min ) {
                    min = cnt - target;
                    height0 = height;
                    width0 = width;
                }

                if ( height == width ) {
                    stop = true;
                }
            }
        }
    }

    cout << height0 * width0 << endl;

    return 0;
}
