#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 100;

    logic integer compute_result(integer x) = 
        x * (1 + (x / 2) + (x / 10) + (x / 100));

    lemma bound_lemma:
        \forall integer x; 
        is_valid_input(x) ==> 
        compute_result(x) <= 100 * 62;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x) {
    // Variable declarations at scope top
    uint32_t result;
    uint32_t term;
    
    //@ assert 1 <= x && x <= 100;
    
    term = 1 + (x / 2) + (x / 10) + (x / 100);
    //@ assert term <= 62;
    
    //@ assert x * term <= 6200;
    
    result = x * term;
    
    //@ assert result == compute_result(x);
    
    return result;
}
