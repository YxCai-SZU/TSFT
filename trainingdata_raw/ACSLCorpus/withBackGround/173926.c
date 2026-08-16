#include <stdbool.h>

/*@ predicate in_range(integer v) = 1 <= v && v <= 10000; */

/*@
    requires in_range(d) && in_range(t) && in_range(s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    int carib;
    int taxi;
    int sub;
    bool result;

    carib = d;
    taxi = t;
    sub = s;

    //@ assert in_range(sub);
    //@ assert in_range(taxi);
    //@ assert sub * taxi <= 10000 * 10000;

    result = (sub * taxi >= carib);
    return result;
}
