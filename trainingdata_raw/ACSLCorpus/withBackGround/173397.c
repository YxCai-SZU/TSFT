#include <stdbool.h>

/*@
    predicate bounds(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer max_product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        bounds(1, t, s) ==> max_product(t, s) <= 10000 * 10000;
*/

/*@
    requires bounds(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned long d, unsigned long t, unsigned long s)
{
    bool result;

    //@ assert bounds(d, t, s);
    //@ assert max_product(t, s) <= 10000 * 10000;

    if (d <= t * s) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
