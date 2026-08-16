#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t sa;
    int64_t sc;
    int64_t s;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert ((a) * (b)) >= 1;
    sa = a * b;

    //@ assert ((c) * (d)) >= 1;
    sc = c * d;

    if (sa > sc) {
        s = sa;
        //@ assert s == ((a) * (b));
    } else {
        s = sc;
        //@ assert s == ((c) * (d));
    }

    //@ assert s >= 1;
    return s;
}
