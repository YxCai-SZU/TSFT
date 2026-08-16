#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    ensures \result == (c - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at top of scope
    long diff;
    bool result;

    //@ assert 0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    //@ assert 0 <= k && k <= 123;

    diff = c - a;
    //@ assert diff == c - a;
    
    result = diff <= k;
    //@ assert result == (c - a <= k);
    
    return result;
}
