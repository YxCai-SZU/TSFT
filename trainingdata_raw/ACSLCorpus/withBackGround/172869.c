#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 1000000000 &&
        1 <= m && m <= 1000000000;

    logic integer compute_result(integer n, integer m) =
        n > m ? 2 * m : n + (m - n) / 4;
*/

/*@
    requires valid_range(n, m);
    assigns \nothing;
    ensures \result == compute_result(n, m);
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans;
    
    if (n > m) {
        ans = 2 * m;
        //@ assert ans == 2 * m;
    } else {
        ans = n + (m - n) / 4;
        //@ assert ans == n + (m - n) / 4;
    }
    
    return ans;
}
