#include <stddef.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 500 && 1 <= m <= 500;
    
    predicate result_valid(integer res) =
        res >= 1 && res <= 500;
*/

/*@
    requires valid_range(n, m);
    ensures result_valid(\result);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t ans;
    
    // Ensure there is always at least one sure shot
    if (n > m) {
        ans = n - m + 1;
    } else {
        ans = 1;
    }
    
    // Ensure ans does not exceed the total number of shots
    if (ans > m) {
        ans = m;
    }
    
    //@ assert ans >= 1;
    //@ assert ans <= 500;
    
    return ans;
}
