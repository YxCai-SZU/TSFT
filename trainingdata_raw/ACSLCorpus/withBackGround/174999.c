#include <stdbool.h>

/*@ predicate is_negative(integer number) = number < 0; */

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at top of scope
    bool result;

    if (e - a > k)
    {
        result = false;
    }
    else
    {
        //@ assert e - a <= k;
        result = true;
    }

    return result;
}
