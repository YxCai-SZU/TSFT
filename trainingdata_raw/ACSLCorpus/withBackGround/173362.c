#include <stdint.h>
#include <limits.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer min_val(integer n, integer m) =
        n < m ? n : m;

    logic integer func_result(integer n, integer m) =
        2 * min_val(n, m) <= n + m ?
        min_val(n, m) + ((n + m - 2 * min_val(n, m)) / 4) :
        (n + m - 1) / 2;

    lemma result_bounds:
        \forall integer n, m;
        is_valid_params(n, m) ==> 
        func_result(n, m) <= n + m && func_result(n, m) >= 0;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result == func_result(n, m);
    ensures \result <= n + m;
    ensures \result >= 0;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t min_val;
    uint64_t ans;
    
    //@ assert n + m <= UINT64_MAX;
    min_val = n < m ? n : m;
    
    //@ assert 2 * min_val <= n + m;
    //@ assert min_val >= 0;
    //@ assert min_val <= UINT64_MAX / 2;
    
    if (2 * min_val <= n + m) {
        ans = min_val + ((n + m - 2 * min_val) / 4);
    } else {
        ans = (n + m - 1) / 2;
    }
    
    return ans;
}
