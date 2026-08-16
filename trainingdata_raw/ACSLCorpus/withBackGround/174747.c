#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    logic integer distance_covered(integer t, integer s) = t * s;

    lemma bounds_mult:
        \forall integer t, s;
            1 <= t <= 10000 && 1 <= s <= 10000 ==> t * s <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int dist;
    int time;
    int speed;
    int distance_covered;
    bool result;

    dist = d;
    time = t;
    speed = s;

    //@ assert 1 <= dist <= 10000;
    //@ assert 1 <= time <= 10000;
    //@ assert 1 <= speed <= 10000;
    //@ assert time * speed <= 10000 * 10000;

    distance_covered = time * speed;
    result = distance_covered >= dist;

    return result;
}
