#include <stdint.h>

/*@ predicate valid_params(integer n, integer k) =
        1 <= k && k <= n && n <= 50;
*/

/*@ lemma ans_bounds: \forall integer n, k, ans;
        valid_params(n, k) && ans == n - k + 1 ==>
        1 <= ans && ans <= n;
*/

/*@ requires valid_params(n, k);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k) {
    int64_t ans;
    
    ans = n - k + 1;
    
    if (k == 1) {
        //@ assert ans == n;
        return 1;
    } else {
        //@ assert n >= 1 && n <= 50;
        //@ assert k >= 1 && k <= 50;
        //@ assert ans >= 1 && ans <= n;
        return ans;
    }
}
