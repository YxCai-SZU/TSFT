#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123 &&
        0 <= (b) <= 123 &&
        0 <= (c) <= 123 &&
        0 <= (d) <= 123 &&
        0 <= (e) <= 123 &&
        0 <= (k) <= 123 &&
        (a) < (b) &&
        (b) < (c) &&
        (c) < (d) &&
        (d) < (e));
    ensures \result == (((e) - (a)) <= k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;

    //@ assert (0 <= (a) <= 123 &&         0 <= (b) <= 123 &&         0 <= (c) <= 123 &&         0 <= (d) <= 123 &&         0 <= (e) <= 123 &&         0 <= (k) <= 123 &&         (a) < (b) &&         (b) < (c) &&         (c) < (d) &&         (d) < (e));
    //@ assert a < e;
    dist = e - a;
    //@ assert dist == ((e) - (a));
    //@ assert dist >= 0;
    //@ assert dist <= 123;

    if (dist <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
