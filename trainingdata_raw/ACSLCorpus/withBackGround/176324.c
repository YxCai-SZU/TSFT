#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer func_result(integer n) = (n - 1) / 2 + 1;
    
    lemma result_bounds: \forall integer n; is_valid_n(n) ==> 
        func_result(n) >= 1 && func_result(n) <= n;
*/

/*@
    requires is_valid_n(n);
    ensures \result == func_result(n);
    ensures \result >= 1;
    ensures \result <= n;
*/
uint32_t func(uint32_t n)
{
    uint32_t n_minus_1;
    uint32_t half_n_minus_1;
    uint32_t result;
    
    n_minus_1 = n - 1;
    half_n_minus_1 = n_minus_1 / 2;
    result = half_n_minus_1 + 1;
    
    //@ assert result == (n - 1) / 2 + 1;
    //@ assert result >= 1;
    //@ assert result <= n;
    
    return result;
}
