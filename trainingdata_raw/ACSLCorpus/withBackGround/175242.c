#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k, integer x, integer y) =
        1 <= n <= 10000 &&
        1 <= k <= 10000 &&
        1 <= y < x <= 10000;

    logic integer result_formula(integer n, integer k, integer x, integer y) =
        n <= k ? n * x : k * x + (n - k) * y;

    lemma bounds_preserved:
        \forall integer n, k, x, y;
        valid_params(n, k, x, y) ==>
        result_formula(n, k, x, y) <= 200000000;
*/

/*@
    requires valid_params(n, k, x, y);
    ensures \result == result_formula(n, k, x, y);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k, uint64_t x, uint64_t y) {
    uint64_t result;

    //@ assert valid_params(n, k, x, y);
    
    if (n <= k) {
        //@ assert result_formula(n, k, x, y) == n * x;
        result = n * x;
    } else {
        //@ assert result_formula(n, k, x, y) == k * x + (n - k) * y;
        result = k * x + (n - k) * y;
    }
    
    return result;
}
