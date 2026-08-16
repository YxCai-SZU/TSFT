#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && 0 <= k && n <= 100000 && k <= n;

    logic integer compute_ans(integer n, integer k) =
        n - k < 0 ? -(n - k) : n - k;

    lemma ans_bounds: \forall integer n, k, ans;
        valid_params(n, k) && ans == compute_ans(n, k) ==> 0 <= ans && ans <= n;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int k)
{
    int ans;
    
    //@ assert valid_params(n, k);
    
    if (n - k < 0) {
        ans = -(n - k);
    } else {
        ans = n - k;
    }
    
    //@ assert ans == compute_ans(n, k);
    //@ assert 0 <= ans && ans <= n;
    
    return ans;
}
