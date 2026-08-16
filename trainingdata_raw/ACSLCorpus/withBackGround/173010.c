#include <stdbool.h>

/*@
    predicate bounds(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        bounds(1, t, s) ==> product(t, s) <= 10000 * 10000;
*/

/*@
    requires bounds(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    long product_val;
    bool result;

    //@ assert t >= 0 && t <= 10000;
    //@ assert s >= 0 && s <= 10000;
    //@ assert product(t, s) <= 10000 * 10000;

    product_val = t * s;

    if (d <= product_val)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (d <= product_val);
    return result;
}
