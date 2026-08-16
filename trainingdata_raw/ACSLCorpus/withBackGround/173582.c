/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= k && k <= 3;
*/

/*@
    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        k <= a ? k : a - (k > a + b ? c : (k - a - b > 0 ? k - a - b : 0));
*/

/*@
    lemma ans_bounds:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> -100 <= compute_ans(a, b, c, k) <= 100;
*/

#include <stdint.h>

/*@
    requires valid_params(a, b, c, k);
    ensures -100 <= \result && \result <= 100;
*/
int64_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int64_t ans = 0;
    uint32_t k_remaining = k;
    
    //@ assert k_remaining == k;
    
    if (k_remaining > a) {
        //@ assert k_remaining > a;
        ans += (int64_t)a;
        k_remaining -= a;
        //@ assert k_remaining == k - a;
    } else {
        //@ assert k_remaining <= a;
        ans += (int64_t)k_remaining;
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }
    
    //@ assert ans >= 0 && ans <= 100;
    
    if (k_remaining > b) {
        //@ assert k_remaining > b;
        k_remaining -= b;
        //@ assert k_remaining == k - a - b || k_remaining == k - b;
    } else {
        //@ assert k_remaining <= b;
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }
    
    if (k_remaining > c) {
        //@ assert k_remaining > c;
        ans -= (int64_t)c;
        k_remaining -= c;
        //@ assert k_remaining == k - a - b - c || k_remaining == k - b - c;
    } else {
        //@ assert k_remaining <= c;
        ans -= (int64_t)k_remaining;
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }
    
    //@ assert k_remaining == 0;
    //@ assert ans >= -100 && ans <= 100;
    
    return ans;
}
