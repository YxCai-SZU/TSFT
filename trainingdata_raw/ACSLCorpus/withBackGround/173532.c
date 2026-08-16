#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer compute_result(integer n, integer m) =
        100 * (m - 1) + 1900 * (n - m);

    lemma bounds_lemma:
        \forall integer n, m;
            valid_params(n, m) ==>
                100 * (m - 1) >= 0 &&
                1900 * (n - m) >= 0 &&
                100 * (m - 1) <= 100 * 4 &&
                1900 * (n - m) <= 1900 * 100;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at scope top
    int32_t ans;
    
    //@ assert m > 0 && m <= 5;
    //@ assert n > 0 && n <= 100;
    //@ assert 100 * ((int32_t)m - 1) >= 0;
    //@ assert 1900 * ((int32_t)n - (int32_t)m) >= 0;
    //@ assert 100 * ((int32_t)m - 1) <= 100 * 4;
    //@ assert 1900 * ((int32_t)n - (int32_t)m) <= 1900 * 100;
    
    ans = 100 * ((int32_t)m - 1) + 1900 * ((int32_t)n - (int32_t)m);
    return ans;
}
