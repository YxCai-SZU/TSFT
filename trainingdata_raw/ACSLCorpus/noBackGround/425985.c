#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000 &&
        (a) <= (b) &&
        (c) <= (d));
    ensures \result >= 0;
    ensures \result <= d - c;
    ensures \result <= b - a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t y;
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 10000 &&         1 <= (b) && (b) <= 10000 &&         1 <= (c) && (c) <= 10000 &&         1 <= (d) && (d) <= 10000 &&         (a) <= (b) &&         (c) <= (d));

    if (b < c) {
        x = b;
    } else {
        x = c;
    }

    if (a > d) {
        y = a;
    } else {
        y = d;
    }

    if (x - y > 0) {
        ans = x - y;
    } else {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= d - c;
    //@ assert ans <= b - a;

    return ans;
}
