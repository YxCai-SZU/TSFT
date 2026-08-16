#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 200000 && 1 <= k <= n + 1;

    logic integer abs_i64(integer x) = x < 0 ? -x : x;

    logic integer n_unsigned_val(integer n) = abs_i64(n);
    logic integer k_unsigned_val(integer k) = abs_i64(k);
    logic integer n_add_k_val(integer n, integer k) = n_unsigned_val(n) + k_unsigned_val(k);

    lemma ans_bounds_lemma:
        \forall integer n, k, ans, i;
            valid_params(n, k) && 0 <= i <= n_add_k_val(n, k) && 0 <= ans < 1000000007 && ans <= i ==>
            ans <= n_add_k_val(n, k);
*/

/*@
    requires valid_params(n, k);
    ensures 0 <= \result < 1000000007;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k) {
    uint64_t n_unsigned;
    uint64_t k_unsigned;
    uint64_t n_add_k;
    uint64_t ans;
    uint64_t i;

    //@ assert valid_params(n, k);
    
    n_unsigned = (n < 0) ? (uint64_t)(-n) : (uint64_t)n;
    //@ assert n_unsigned == n_unsigned_val(n);
    
    k_unsigned = (k < 0) ? (uint64_t)(-k) : (uint64_t)k;
    //@ assert k_unsigned == k_unsigned_val(k);
    
    n_add_k = n_unsigned + k_unsigned;
    //@ assert n_add_k == n_add_k_val(n, k);
    
    ans = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n_add_k;
        loop invariant 0 <= ans < 1000000007;
        loop invariant n_add_k == n_unsigned_val(n) + k_unsigned_val(k);
        loop invariant n_unsigned == n_unsigned_val(n);
        loop invariant k_unsigned == k_unsigned_val(k);
        loop invariant valid_params(n, k);
        loop invariant ans <= i;
        loop assigns i, ans;
        loop variant n_add_k - i;
    */
    while (i < n_add_k) {
        if (i <= n_unsigned && n_unsigned <= i + k_unsigned) {
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= ans < 1000000007 + n_add_k;
    
    /*@
        loop invariant 0 <= ans <= 1000000007 + n_add_k;
        loop invariant n_add_k == n_add_k_val(n, k);
        loop invariant valid_params(n, k);
        loop assigns ans;
        loop variant ans;
    */
    while (ans >= 1000000007) {
        ans -= 1000000007;
    }
    
    //@ assert 0 <= ans < 1000000007;
    
    /*@
        loop invariant -1000000007 < ans < 1000000007;
        loop invariant n_add_k == n_add_k_val(n, k);
        loop invariant valid_params(n, k);
        loop assigns ans;
        loop variant 1000000007 + ans;
    */
    while (ans < 0) {
        ans += 1000000007;
    }
    
    //@ assert 0 <= ans < 1000000007;
    return (int64_t)ans;
}
