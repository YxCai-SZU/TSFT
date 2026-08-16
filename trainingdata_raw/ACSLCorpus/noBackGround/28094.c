#include <stdbool.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
    requires k >= 0;
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    ensures \result == (e - a <= k);
    ensures ((\result) == ((e) - (a) <= (k)));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at top of scope
    bool result;
    
    if (e - a > k)
    {
        result = false;
        //@ assert result == false;
    }
    else
    {
        //@ assert e - a <= k;
        result = true;
    }
    
    //@ assert result == (e - a <= k);
    return result;
}
