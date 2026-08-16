#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    ensures \result <= 100000000;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sb;
    int res;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    sa = a * b;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    sb = c * d;

    if (sa > sb) {
        res = sa;
    } else {
        res = sb;
    }

    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= ((a) * (b)) && res >= ((c) * (d));
    //@ assert res <= 100000000;

    return res;
}
