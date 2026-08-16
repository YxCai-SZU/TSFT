#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= n &&
        m <= 5;

    logic integer compute_result(integer n, integer m) =
        100 * (m - 1) + (n - m);

    lemma result_nonnegative:
        \forall integer n, m; valid_params(n, m) ==> compute_result(n, m) >= 0;

    lemma result_bounded:
        \forall integer n, m; valid_params(n, m) ==> compute_result(n, m) <= 100 * 4 + 100;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans;
    //@ assert 1 <= m && m <= 5;
    //@ assert 100 * (m - 1) >= 0;
    //@ assert 100 * (m - 1) <= 100 * 4;
    //@ assert 1 <= n && n <= 100;
    //@ assert 100 * (m - 1) + (n - m) >= 0;
    //@ assert 100 * (m - 1) + (n - m) <= 100 * 4 + 100;
    
    ans = 100 * ((int32_t)m - 1) + ((int32_t)n - (int32_t)m);
    return ans;
}
