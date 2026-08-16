#include <stdint.h>
/*@
    predicate valid_params(uint64_t n, uint64_t k) =
        2 <= k && k <= n && n <= 100000000000000000;

    logic integer floor_div(integer n, integer k) =
        (n - 2) / (k - 1);

    lemma ans_bounds:
        \forall uint64_t n, uint64_t k;
        valid_params(n, k) ==>
        floor_div(n, k) <= (n - 2) / (k - 1) + 1 &&
        floor_div(n, k) >= (n - 2) / (k - 1);
*/

/*@
    requires valid_params(n, k);
    ensures \result <= (n - 2) / (k - 1) + 1;
    ensures \result >= (n - 2) / (k - 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k) {
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t tmp_n_minus_2;
    uint64_t tmp_k_minus_1;
    uint64_t quotient;
    uint64_t remainder;

    // Precondition implies these are safe
    //@ assert n - 2 >= 0;
    tmp_n_minus_2 = n - 2;
    
    //@ assert k - 1 > 0;
    tmp_k_minus_1 = k - 1;
    
    quotient = tmp_n_minus_2 / tmp_k_minus_1;
    remainder = tmp_n_minus_2 % tmp_k_minus_1;
    
    //@ assert quotient <= 100000000000000000;
    //@ assert quotient + 1 <= 100000000000000001;
    
    if (remainder == 0) {
        ans = quotient;
        //@ assert ans == (n - 2) / (k - 1);
    } else {
        ans = quotient + 1;
        //@ assert ans == (n - 2) / (k - 1) + 1;
    }
    
    return ans;
}
