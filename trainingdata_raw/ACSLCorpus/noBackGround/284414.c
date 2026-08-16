#include <stdbool.h>

/*@
    requires ((a) >= -100 && (b) <= 100 && (c) >= -100 && (d) <= 100 &&
        (a) <= (b) && (c) <= (d));
    ensures \result == true <==> ((a) <= (d) && (c) <= (b));
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    //@ assert a <= b && c <= d;
    return a <= d && c <= b;
}
