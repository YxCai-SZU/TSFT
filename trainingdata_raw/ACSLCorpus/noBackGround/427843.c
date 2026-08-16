#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t y;
    int64_t res;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a > b) {
        x = a;
    } else {
        x = b;
    }
    //@ assert x == (((a) > (b)) ? (a) : (b));

    if (c > d) {
        y = c;
    } else {
        y = d;
    }
    //@ assert y == (((c) > (d)) ? (c) : (d));

    //@ assert x == a || x == b;
    //@ assert y == c || y == d;
    //@ assert 1 <= x <= 10000;
    //@ assert 1 <= y <= 10000;

    //@ assert x + y <= 9223372036854775807;
    res = x + y;

    //@ assert res == a + c || res == a + d || res == b + c || res == b + d;
    return res;
}
