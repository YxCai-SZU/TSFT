#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    requires 0 <= k <= 123;
    ensures \result == true <==> (e - a) <= k;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;

    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    //@ assert 0 <= k <= 123;

    dist = e - a;
    //@ assert dist == e - a;

    if (dist < 0)
    {
        dist = -dist;
    }
    //@ assert dist == (((e - a) < 0) ? -(e - a) : (e - a));

    //@ assert (((e - a) < 0) ? -(e - a) : (e - a)) >= 0;

    if (dist <= k)
    {
        //@ assert (e - a) <= k;
        return true;
    }
    else
    {
        //@ assert (e - a) > k;
        return false;
    }
}
