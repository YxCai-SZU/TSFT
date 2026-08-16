#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer func_spec(integer r) = 3 * (r * r) * 3;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    
    pi = 3;
    
    //@ assert r * r <= 10000;
    //@ assert 3 * (r * r) <= 30000;
    //@ assert 3 * (r * r) * 3 <= 90000;
    
    ans = 3 * (r * r) * pi;
    return ans;
}
