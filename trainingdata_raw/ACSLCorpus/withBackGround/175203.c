#include <stdbool.h>

/*@
    predicate bounds(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    lemma product_bound:
        \forall integer t, s;
        bounds(1, t, s) ==> t * s <= 10000 * 10000;

    lemma d_bound:
        \forall integer d, t, s;
        bounds(d, t, s) && t * s <= 10000 * 10000 ==> d <= 10000 * 10000;
*/

/*@
    requires bounds(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    //@ assert bounds(d, t, s);
    //@ assert t * s <= 10000 * 10000;
    //@ assert d <= 10000 * 10000;
    
    return d <= t * s;
}
