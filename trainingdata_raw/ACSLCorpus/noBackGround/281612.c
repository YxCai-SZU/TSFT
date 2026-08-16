#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (a - b * c < d);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    // Variable declarations at scope top
    long diff;
    bool result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert b * c <= 10000 * 10000;

    diff = a - b * c;
    result = diff < d;
    return result;
}
