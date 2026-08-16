#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    lemma time_speed_bound: \forall integer t, s;
        1 <= t && t <= 10000 && 1 <= s && s <= 10000 ==>
        1 <= t * s && t * s <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long dist;
    long time;
    long speed;
    bool result;

    dist = d;
    time = t;
    speed = s;

    //@ assert 1 <= time && time <= 10000;
    //@ assert 1 <= speed && speed <= 10000;
    //@ assert 1 <= time * speed && time * speed <= 10000 * 10000;

    result = (dist <= time * speed);
    return result;
}
