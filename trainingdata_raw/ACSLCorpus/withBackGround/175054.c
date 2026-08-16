#include <stdbool.h>

/*@
    predicate valid_inputs(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000 &&
        d >= 0 &&
        t >= 0 &&
        s >= 0;

    logic integer safe_product(integer t, integer s) = t * s;

    predicate result_condition(integer d, integer t, integer s, bool r) =
        r == (d <= safe_product(t, s));
*/

/*@
    requires valid_inputs(d, t, s);
    ensures result_condition(d, t, s, \result);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long dist = d;
    long time = t;
    long speed = s;

    //@ assert dist >= 0;
    //@ assert time >= 0;
    //@ assert speed >= 0;
    //@ assert time > 0 && speed > 0;
    //@ assert time * speed <= 10000 * 10000;

    return dist <= time * speed;
}
