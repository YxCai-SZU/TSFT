#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer s, t;
        1 <= s <= 10000 && 1 <= t <= 10000 ==>
        safe_mult(s, t) <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    long distance;
    long time;
    long speed;
    long covered_distance;
    bool result;

    distance = (long)d;
    time = (long)t;
    speed = (long)s;

    //@ assert speed * time <= 10000 * 10000;
    //@ assert distance == (long)d;

    covered_distance = speed * time;
    result = (covered_distance >= distance);
    return result;
}
