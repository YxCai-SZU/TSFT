#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    predicate ans_correct(integer r, integer ans) = ans == 3 * (r * r);
*/

/*@
    requires r_in_range(r);
    ensures ans_correct(r, \result);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t ans;
    int64_t temp;
    
    //@ assert 1 * 1 <= r * r <= 100 * 100;
    temp = r * r;
    
    //@ assert 3 * 1 * 1 <= 3 * temp <= 3 * 100 * 100;
    ans = 3 * temp;
    
    return ans;
}
