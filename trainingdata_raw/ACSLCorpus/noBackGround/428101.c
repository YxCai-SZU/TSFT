#include <stdbool.h>

/*@
  requires ((1) <= (a) && (a) <= (100));
  requires ((1) <= (b) && (b) <= (100));
  requires ((1) <= (c) && (c) <= (100));
  ensures \result == true <==> (((a) < (c) && (b) > (c)) || ((a) > (c) && (b) < (c)));
*/
bool func(int a, int b, int c) {
    int x;
    int y;
    int temp;

    x = a;
    y = b;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;

        //@ assert x <= y;
    }

    if (c > x && c < y) {
        return true;
    } else {
        return false;
    }
}
