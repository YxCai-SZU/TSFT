#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;
    long product;

    //@ assert (1 <= (s) <= 10000);
    //@ assert (1 <= (t) <= 10000);
    //@ assert 1 <= ((s) * (t)) <= 10000 * 10000;

    product = s * t;
    result = (product >= d);

    return result;
}
