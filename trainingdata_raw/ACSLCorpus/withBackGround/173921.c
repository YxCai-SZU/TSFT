#include <stdbool.h>

/*@
    predicate bounds(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    lemma mult_bounds:
        \forall integer t, s;
            bounds(1, t, s) ==> (t * s) <= 100000000;

    lemma mult_nonnegative:
        \forall integer t, s;
            bounds(1, t, s) ==> (t * s) >= 0;
*/

/*@
    requires bounds(d, t, s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int distance;
    int speed;
    int time;
    bool can_arrive_on_time;

    distance = d;
    speed = s;
    time = t;

    //@ assert bounds(distance, time, speed);
    //@ assert speed > 0 && time > 0;
    //@ assert speed <= 10000 && time <= 10000;
    //@ assert (long long)time * (long long)speed <= 10000LL * 10000LL;
    //@ assert time * speed >= 0;

    can_arrive_on_time = (time * speed >= distance);

    //@ assert can_arrive_on_time == (t * s >= d);
    return can_arrive_on_time;
}
