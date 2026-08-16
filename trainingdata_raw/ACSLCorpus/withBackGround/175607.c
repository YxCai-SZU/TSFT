#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer calculate_x(integer n) = n * 800;
    logic integer calculate_quotient(integer n) = n / 15;
    logic integer calculate_y(integer n) = (n / 15) * 200;
    logic integer calculate_ans(integer n) = n * 800 - (n / 15) * 200;
    logic integer calculate_max(integer ans) = ans < 0 ? 0 : ans;
    
    lemma quotient_bounds: \forall integer n; is_valid_n(n) ==> 0 <= n/15 && n/15 <= n;
    lemma remainder_nonneg: \forall integer n, q; n >= 0 && q >= 0 && q <= n/15 ==> n - q*15 >= 0;
    lemma ans_formula: \forall integer n; is_valid_n(n) ==> calculate_ans(n) == calculate_x(n) - calculate_y(n);
*/

/*@
    requires is_valid_n(n);
    ensures \result == calculate_max(calculate_ans(n));
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t x;
    int32_t quotient;
    int32_t remainder;
    int32_t y;
    int32_t ans;
    int32_t max_value;
    
    x = (int32_t)n * 800;
    
    quotient = 0;
    remainder = (int32_t)n;
    
    /*@
        loop invariant 0 <= quotient <= (int32_t)n / 15;
        loop invariant remainder == (int32_t)n - quotient * 15;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15) {
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == calculate_ans((int32_t)n);
    
    if (ans < 0) {
        max_value = 0;
    } else {
        max_value = ans;
    }
    
    //@ assert max_value == calculate_max(calculate_ans((int32_t)n));
    
    return max_value;
}
