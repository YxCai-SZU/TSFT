#include <stdint.h>

/*@
    predicate valid_params(integer n, integer w) =
        1 <= n <= 100 && 1 <= w <= 100;
    
    logic integer product(integer n, integer w) = n * w;
    
    lemma product_bounded: \forall integer n, w; 
        valid_params(n, w) ==> product(n, w) <= 10000;
*/

/*@
    requires valid_params(n, w);
    ensures \result == product(n, w);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t w) {
    // Variable declarations at top of scope
    uint32_t ans;
    int32_t result;
    
    //@ assert valid_params(n, w);
    
    //@ assert product(n, w) <= 10000;
    
    ans = n * w;
    result = (int32_t)ans;
    
    //@ assert result == product(n, w);
    return result;
}
