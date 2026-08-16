#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    predicate result_range(integer ret) =
        ret >= 0 && ret <= 1;
*/

/*@
    requires valid_params(n, k);
    ensures result_range(\result);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k) {
    // Variable declarations at scope top
    int32_t ret_val;
    
    if (n % k == 0) {
        ret_val = 0;
    } else {
        ret_val = 1;
    }
    
    //@ assert result_range(ret_val);
    return ret_val;
}

/*@
    requires valid_params(n, k);
    ensures result_range(\result);
    assigns \nothing;
*/
int32_t func2(uint32_t n, uint32_t k) {
    // Variable declarations at scope top
    int32_t ret_val;
    
    if (n % k == 0) {
        //@ assert n % k == 0;
        ret_val = 0;
    } else {
        //@ assert n % k != 0;
        ret_val = 1;
    }
    
    //@ assert result_range(ret_val);
    return ret_val;
}
