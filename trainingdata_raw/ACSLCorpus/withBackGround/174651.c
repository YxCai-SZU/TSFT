#include <stdbool.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer s, t;
            1 <= s <= 10000 && 1 <= t <= 10000 ==> product(s, t) <= 10000 * 10000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int max_speed;
    unsigned int max_time;
    unsigned int distance;
    bool result;

    max_speed = s;
    max_time = t;
    distance = d;

    //@ assert max_speed <= 10000;
    //@ assert max_time <= 10000;
    //@ assert max_speed * max_time <= 10000 * 10000;

    result = max_speed * max_time >= distance;
    return result;
}
