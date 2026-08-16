#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer t, s;
            valid_range(t) && valid_range(s) ==> 
            safe_mult(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int distance;
    int time;
    int speed;
    bool result;

    distance = d;
    time = t;
    speed = s;

    //@ assert valid_range(time) && valid_range(speed);
    //@ assert time * speed <= 10000 * 10000;

    if (time * speed < distance)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    //@ assert result == (time * speed >= distance);
    return result;
}
