#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n <= 1000000000;

    logic integer floor_div_11(integer n) = n / 11;

    logic integer lower_bound(integer n) = 2 * floor_div_11(n);
    logic integer upper_bound(integer n) = 2 * floor_div_11(n) + 2;

    lemma div_nonnegative: \forall integer n; is_valid_n(n) ==> floor_div_11(n) >= 0;
    lemma mul_no_overflow1: \forall integer n; is_valid_n(n) ==> floor_div_11(n) * 2 <= n;
    lemma mul_no_overflow2: \forall integer n; is_valid_n(n) ==> floor_div_11(n) * 2 + 1 <= n + 1;
    lemma ans_property1: \forall integer n, ans; is_valid_n(n) && n % 11 == 0 && ans == floor_div_11(n) * 2 ==> 
                         ans == lower_bound(n) && ans <= upper_bound(n);
    lemma ans_property2: \forall integer n, ans; is_valid_n(n) && n % 11 != 0 && ans == floor_div_11(n) * 2 + 1 ==> 
                         lower_bound(n) <= ans <= upper_bound(n);
*/

/*@
    requires is_valid_n(n);
    assigns \nothing;
    ensures lower_bound(n) <= \result <= upper_bound(n);
*/
uint32_t func(uint32_t n) {
    uint32_t ans;
    
    if (n % 11 == 0) {
        //@ assert floor_div_11(n) <= floor_div_11(n);
        //@ assert floor_div_11(n) >= 0;
        //@ assert floor_div_11(n) * 2 <= n;
        ans = (n / 11) * 2;
        //@ assert ans == floor_div_11(n) * 2;
    } else {
        //@ assert floor_div_11(n) <= floor_div_11(n);
        //@ assert floor_div_11(n) >= 0;
        //@ assert floor_div_11(n) * 2 + 1 <= n + 1;
        ans = (n / 11) * 2 + 1;
        //@ assert ans == floor_div_11(n) * 2 + 1;
    }
    
    return ans;
}
