#include <stdint.h>

/*@
    predicate lower_bound(integer r) = 1 <= r <= 100;
    predicate result_valid(integer r, integer res) = res == 3 * r * r;
    predicate within_i64_max(integer r) = 3 * r * r < 9223372036854775807;
*/

/*@
    requires lower_bound(r);
    ensures result_valid(r, \result);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t res;

    //@ assert lower_bound(r);
    //@ assert within_i64_max(r);
    
    res = 3 * r * r;
    
    //@ assert result_valid(r, res);
    return res;
}
