#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
    ensures \result == 1 <==> ((k) >= (b) - (a) || (k) >= (c) - (b) || (k) >= (d) - (c) || (k) >= (e) - (d) || (k) >= (e) - (a));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool ans;

    ans = false;
    //@ assert ans == \false;

    if (k >= b - a || k >= c - b || k >= d - c || k >= e - d || k >= e - a)
    {
        ans = true;
        //@ assert ans == \true;
    }

    //@ assert ans == 1 <==> ((k) >= (b) - (a) || (k) >= (c) - (b) || (k) >= (d) - (c) || (k) >= (e) - (d) || (k) >= (e) - (a));
    return ans;
}
