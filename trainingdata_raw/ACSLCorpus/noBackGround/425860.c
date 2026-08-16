#include <stdbool.h>

/*@
    requires (-1000000000 <= (a) <= (b) <= 1000000000);
    requires (-1000000000 <= (c) <= (d) <= 1000000000);
    ensures \result == (c <= b && a <= d);
*/
bool func(long a, long b, long c, long d)
{
    //@ assert (-1000000000 <= (a) <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= (d) <= 1000000000);
    return c <= b && a <= d;
}
