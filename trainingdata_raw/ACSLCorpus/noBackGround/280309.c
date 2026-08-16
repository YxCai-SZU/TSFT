#include <stdbool.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == true <==> (((c) <= (a) && (a) <= (d)) || ((a) <= (c) && (c) <= (b)) || ((a) <= (d) && (d) <= (b)));
*/
bool func(long long a, long long b, long long c, long long d)
{
    long long max;
    long long min;

    //@ assert a <= b && c <= d;

    if (a > c) {
        max = a;
    } else {
        max = c;
    }

    if (b < d) {
        min = b;
    } else {
        min = d;
    }

    //@ assert max == a || max == c;
    //@ assert min == b || min == d;

    if (max <= min) {
        //@ assert (((c) <= (a) && (a) <= (d)) || ((a) <= (c) && (c) <= (b)) || ((a) <= (d) && (d) <= (b)));
        return true;
    } else {
        //@ assert !(((c) <= (a) && (a) <= (d)) || ((a) <= (c) && (c) <= (b)) || ((a) <= (d) && (d) <= (b)));
        return false;
    }
}
