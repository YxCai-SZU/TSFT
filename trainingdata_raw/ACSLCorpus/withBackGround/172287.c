#include <stdint.h>

/*@
    predicate valid_params(integer n, integer d) =
        1 <= n <= 20 && 1 <= d <= 20;

    logic integer ceiling_div(integer n, integer d) =
        (n + 2 * d - 1) / (2 * d);

    lemma result_non_negative:
        \forall integer n, d; valid_params(n, d) ==> ceiling_div(n, d) >= 0;
*/

/*@
    requires valid_params(n, d);
    ensures \result >= 0;
    ensures \result == (int)ceiling_div(n, d);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t d) {
    uint32_t x;
    uint32_t result;
    
    x = n + 2 * d - 1;
    //@ assert x == n + 2 * d - 1;
    
    result = x / (2 * d);
    //@ assert result == (n + 2 * d - 1) / (2 * d);
    
    return (int32_t)result;
}
