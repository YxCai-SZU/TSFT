#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer func_result(integer n) = (n - 1) / 2 + 1;
    
    lemma result_bounds: \forall integer n; is_valid_n(n) ==> 
        func_result(n) >= 1 && func_result(n) <= n;
    
    lemma arithmetic_bounds: \forall integer n; is_valid_n(n) ==> 
        (n - 1) / 2 <= 49 && func_result(n) <= 50;
*/

/*@
    requires is_valid_n(n);
    ensures \result == func_result(n);
    ensures \result >= 1;
    ensures \result <= n;
*/
uint32_t func(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n > 0;
    //@ assert n <= 100;
    //@ assert (n - 1) / 2 <= 49;
    //@ assert (n - 1) / 2 + 1 <= 50;
    
    result = (n - 1) / 2 + 1;
    return result;
}
