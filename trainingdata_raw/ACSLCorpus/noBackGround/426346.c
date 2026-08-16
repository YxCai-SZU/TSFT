#include <stdbool.h>

/*@
    requires 1 <= d <= 10000;
    requires 1 <= t <= 10000;
    requires 1 <= s <= 10000;
    ensures \result == (s * t >= d);
*/
bool func(long d, long t, long s)
{
    long dist = d;
    long time = t;
    long speed = s;

    //@ assert (1 <= (speed) <= 10000);
    //@ assert (1 <= (time) <= 10000);
    //@ assert ((speed) * (time)) <= 100000000;
    //@ assert ((speed) * (time)) >= 0;

    return speed * time >= dist;
}
