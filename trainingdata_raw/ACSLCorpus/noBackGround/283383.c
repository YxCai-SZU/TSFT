#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    requires ((k) >= 0 && (k) < 124);
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
    //@ assert a < b && b < c && c < d && d < e;
    //@ assert k >= 0 && k < 124;
    
    result = (e - a <= k);
    
    //@ assert result == (e - a <= k);
    return result;
}
