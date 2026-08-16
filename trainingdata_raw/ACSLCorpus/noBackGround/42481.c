#include <stdbool.h>

/*@ requires (-1000000000 <= (a) <= 1000000000);
    requires (-1000000000 <= (b) <= 1000000000);
    requires (-1000000000 <= (c) <= 1000000000);
    requires (-1000000000 <= (d) <= 1000000000);
    requires ((a) <= (b) && (c) <= (d));
    ensures \result == (b < c || d < a);
 */
bool func(long a, long b, long c, long d)
{
    //@ assert a <= b;
    //@ assert c <= d;
    //@ assert -1000000000 <= a && a <= 1000000000;
    //@ assert -1000000000 <= b && b <= 1000000000;
    //@ assert -1000000000 <= c && c <= 1000000000;
    //@ assert -1000000000 <= d && d <= 1000000000;
    return b < c || d < a;
}
