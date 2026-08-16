#include <stddef.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;
    
    logic integer result(integer n, integer m) = (n + m) / 4;
*/

/*@
    requires valid_range(n, m);
    ensures \result == result(n, m);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at top of scope
    size_t ans;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert n + m <= 200;
    
    ans = (n + m) / 4;
    
    //@ assert ans == result(n, m);
    return ans;
}
