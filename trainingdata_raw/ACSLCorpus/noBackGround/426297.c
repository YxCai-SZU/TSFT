#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) <= 123);
    requires (0 <= (k) <= 123);
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (0 <= (a) < (b) < (c) < (d) < (e) <= 123);
    //@ assert (0 <= (k) <= 123);
    
    result = (e - a <= k);
    
    //@ assert result == (e - a <= k);
    
    return result;
}
