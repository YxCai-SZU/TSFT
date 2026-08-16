#include <stdbool.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bounds: \forall integer t, s;
        is_valid_params(10000, t, s) ==> product(t, s) <= 10000 * 10000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (product(t, s) >= d);
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    int distance;
    int time;
    int speed;
    bool is_negative_distance;
    bool is_negative_time;
    bool is_negative_speed;
    int product;
    bool result;

    distance = (int)d;
    time = (int)t;
    speed = (int)s;

    is_negative_distance = false;
    if (distance < 0)
    {
        is_negative_distance = true;
        distance = -distance;
    }

    is_negative_time = false;
    if (time < 0)
    {
        is_negative_time = true;
        time = -time;
    }

    is_negative_speed = false;
    if (speed < 0)
    {
        is_negative_speed = true;
        speed = -speed;
    }

    //@ assert time == (int)t && speed == (int)s;
    //@ assert product(t, s) <= 10000 * 10000;
    product = time * speed;

    if (product >= distance)
    {
        result = true;
    }
    else
    {
        //@ assert product(t, s) < d;
        result = false;
    }

    return result;
}
