#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= 100);
    requires (0 <= (x) && (x) <= 100);
    ensures \result == (a <= x && (x - a) <= b);
*/
bool func(long long a, long long b, long long x)
{
    long long additional;

    if (a > x)
    {
        //@ assert !(a <= x && (x - a) <= b);
        return false;
    }

    additional = x - a;

    if (additional > b)
    {
        //@ assert !(a <= x && (x - a) <= b);
        return false;
    }

    //@ assert a <= x && (x - a) <= b;
    return true;
}
