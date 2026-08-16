/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        is_valid_params(1, t, s) ==> 1 <= product(t, s) <= 10000 * 10000;

    lemma product_positive:
        \forall integer t, s;
        1 <= t && 1 <= s ==> product(t, s) >= 1;
*/

#include <stdbool.h>

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    int d1;

    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert 1 <= t * s && t * s <= 10000 * 10000;
    //@ assert t * s >= 1;

    d1 = t * s;

    if (d1 < d)
    {
        return false;
    }
    else
    {
        return true;
    }
}
