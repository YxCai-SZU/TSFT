#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    requires a <= b;
    ensures \result == (c >= a && c <= b);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at scope top
    bool ret;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert a <= b;

    if (c >= a && c <= b)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }

    //@ assert ret == (c >= a && c <= b);
    return ret;
}
