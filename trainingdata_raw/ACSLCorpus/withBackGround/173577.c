#include <stdbool.h>

/*@ predicate in_range(integer v) = 1 <= v && v <= 10000; */

/*@
  requires in_range(d) && in_range(t) && in_range(s);
  ensures \result == true <==> d <= t * s;
  assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long distance = d;
    long time = t;
    long speed = s;
    long reach;

    //@ assert time <= 10000;
    //@ assert speed <= 10000;
    //@ assert time * speed <= 10000 * 10000;

    reach = time * speed;

    if (distance <= reach)
    {
        return true;
    }
    else
    {
        return false;
    }
}
