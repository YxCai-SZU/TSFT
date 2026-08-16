#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    lemma product_bounds:
        \forall integer t, s;
        valid_params(1, t, s) ==> 1 <= s * t <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (s * t >= d);
*/
bool func(long d, long t, long s)
{
    bool is_possible = false;

    //@ assert 1 <= s * t <= 10000 * 10000;

    if (d <= s * t)
    {
        is_possible = true;
    }

    //@ assert is_possible == (s * t >= d);

    return is_possible;
}
