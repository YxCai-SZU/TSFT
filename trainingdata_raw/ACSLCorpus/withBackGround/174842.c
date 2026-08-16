#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer base_price(integer n, integer m) =
        190 * (n - m) + 110 * (m - 1);

    lemma price_bound_lemma:
        \forall integer n, m;
            valid_params(n, m) ==> base_price(n, m) <= 190 * n;

    lemma price_nonnegative:
        \forall integer n, m;
            valid_params(n, m) ==> base_price(n, m) >= 0;
*/

/*@
    requires valid_params(n, m);
    ensures \result >= 0;
    ensures \result <= 190 * (int)n;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Declare all variables at the top
    int32_t result = 0;
    int32_t base_price = 0;
    
    //@ assert valid_params(n, m);
    
    if (m == 0) {
        result = 0;
    } else if (n == m) {
        //@ assert 190 * (int)n <= 190 * (int)n;
        result = 190 * (int32_t)n;
    } else {
        //@ assert 1 <= n && n <= 100;
        //@ assert 1 <= m && m <= n;
        //@ assert m <= 5;
        
        //@ assert 110 * (m - 1) <= 110 * 4;
        //@ assert 190 * (n - m) <= 190 * 100;
        //@ assert 110 * (m - 1) + 190 * (n - m) <= 110 * 4 + 190 * 100;
        
        base_price = 190 * (int32_t)(n - m) + 110 * (int32_t)(m - 1);
        result = base_price;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 190 * (int)n;
    return result;
}
