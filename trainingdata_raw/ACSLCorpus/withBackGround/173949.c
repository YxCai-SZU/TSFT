#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        2 <= k <= n <= 1000000000;
*/

/*@
    logic integer func_spec(integer n, integer k) =
        (n - 2) / (k - 1) + 1;
*/

/*@
    lemma arithmetic_bounds:
        \forall integer n, integer k;
        valid_params(n, k) ==>
        n - 2 >= 0 &&
        k - 1 >= 1 &&
        (n - 2) / (k - 1) <= 1000000000 &&
        (n - 2) / (k - 1) + 1 <= 1000000001;
*/

/*@
    requires valid_params(n, k);
    ensures \result == func_spec(n, k);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k) {
    // Variable declarations at top of scope
    uint64_t ans;
    
    //@ assert n >= 2;
    //@ assert k >= 2;
    //@ assert n <= 1000000000;
    //@ assert k <= 1000000000;
    //@ assert n - 2 >= 0;
    //@ assert k - 1 >= 1;
    //@ assert k - 1 > 0;
    //@ assert (n - 2) / (k - 1) <= 1000000000;
    //@ assert (n - 2) / (k - 1) + 1 <= 1000000001;
    
    ans = (n - 2) / (k - 1) + 1;
    
    //@ assert ans == func_spec(n, k);
    return ans;
}
