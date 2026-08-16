#include <stdbool.h>

/*@
  requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);
  ensures \result == (\abs(a - b) <= d || \abs(a - c) <= d || \abs(b - c) <= d);
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int diff3;
    bool result;

    //@ assert (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);

    if (a > b) {
        diff1 = a - b;
    } else {
        diff1 = b - a;
    }
    //@ assert diff1 == \abs(a - b);

    if (a > c) {
        diff2 = a - c;
    } else {
        diff2 = c - a;
    }
    //@ assert diff2 == \abs(a - c);

    if (b > c) {
        diff3 = b - c;
    } else {
        diff3 = c - b;
    }
    //@ assert diff3 == \abs(b - c);

    if (diff1 <= d || diff2 <= d || diff3 <= d) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (\abs(a - b) <= d || \abs(a - c) <= d || \abs(b - c) <= d);
    return result;
}
