#include <stdbool.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    lemma multiplication_bounds:
        \forall integer t, s;
            is_valid_params(1, t, s) ==> t * s <= 10000 * 10000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == true <==> (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int dist = d;
    int time = t;
    int speed = s;
    bool can_reach;

    //@ assert time * speed <= 10000 * 10000;
    can_reach = (dist <= time * speed);
    //@ assert can_reach == true <==> (d <= t * s);
    return can_reach;
}
