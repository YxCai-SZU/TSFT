#include <limits.h>

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires a <= b;
    requires c <= d;
    ensures \result == a * d || \result == a * c || \result == b * d || \result == b * c;
*/
long func(long a, long b, long c, long d) {
    long f;
    long s;
    long res;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);

    if (a * c > a * d) {
        f = a * c;
    } else {
        f = a * d;
    }

    if (b * c > b * d) {
        s = b * c;
    } else {
        s = b * d;
    }

    if (f > s) {
        res = f;
    } else {
        res = s;
    }

    //@ assert res == a * d || res == a * c || res == b * d || res == b * c;
    return res;
}
