#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        valid_params(10000, t, s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    long long distance;
    long long time;
    long long speed;
    bool result;

    distance = (long long)d;
    time = (long long)t;
    speed = (long long)s;

    //@ assert 1 <= time <= 10000;
    //@ assert 1 <= speed <= 10000;
    //@ assert time * speed <= 10000 * 10000;

    if (distance <= time * speed)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (distance <= time * speed);
    return result;
}
