#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer compute_n(integer x) = x / 100;

    logic integer compute_expression(integer x) = 
        (compute_n(x) * 100) + 100;

    predicate result_one_implies(integer x, integer result) =
        result == 1 ==> compute_expression(x) == x;

    predicate result_zero_implies(integer x, integer result) =
        result == 0 ==> compute_expression(x) != x;

    lemma n_bound: \forall integer x; is_valid_x(x) ==> compute_n(x) * 100 <= 100000;
    lemma expression_bound: \forall integer x; is_valid_x(x) ==> compute_expression(x) <= 101000;
*/

/*@
    requires is_valid_x(x);
    ensures \result == 0 || \result == 1;
    ensures result_one_implies(x, \result);
    ensures result_zero_implies(x, \result);
*/
uint64_t func(uint64_t x) {
    uint64_t n;
    uint64_t ans;

    // Variable declarations at top
    n = x / 100;
    ans = 0;

    //@ assert n * 100 <= 100000;
    //@ assert n * 100 + 100 <= 101000;

    if ((n * 100) + 100 == x) {
        ans = 1;
    } else {
        ans = 0;
    }

    return ans;
}
