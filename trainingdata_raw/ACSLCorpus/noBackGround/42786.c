#include <stdbool.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000 &&
        -1000000000 <= (b) <= 1000000000 &&
        (a) <= (b));
    requires (-1000000000 <= (c) <= 1000000000 &&
        -1000000000 <= (d) <= 1000000000 &&
        (c) <= (d));
    ensures \result == (b < c || a > d);
*/
bool func(long a, long b, long c, long d)
{
    long max1;
    long min1;
    long max2;
    long min2;
    bool result;

    //@ assert (-1000000000 <= (a) <= 1000000000 &&         -1000000000 <= (b) <= 1000000000 &&         (a) <= (b));
    //@ assert (-1000000000 <= (c) <= 1000000000 &&         -1000000000 <= (d) <= 1000000000 &&         (c) <= (d));

    max1 = (a > b) ? a : b;
    min1 = (a < b) ? a : b;
    max2 = (c > d) ? c : d;
    min2 = (c < d) ? c : d;

    //@ assert max1 == (((a) > (b)) ? (a) : (b));
    //@ assert min1 == (((a) < (b)) ? (a) : (b));
    //@ assert max2 == (((c) > (d)) ? (c) : (d));
    //@ assert min2 == (((c) < (d)) ? (c) : (d));

    //@ assert max1 < min2 || min1 > max2 ==> (b < c || a > d);

    result = max1 < min2 || min1 > max2;
    //@ assert result == (b < c || a > d);
    return result;
}
