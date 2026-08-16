#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 2 <= a && a <= 100;
    predicate b_in_range(integer b) = 2 <= b && b <= 100;
    predicate result_correct(integer a, integer b, integer result) = 
        result == (a - 1) * (b - 1);
*/

/*@
    logic integer safe_mult(integer a, integer b) = (a - 1) * (b - 1);
*/

/*@
    lemma mult_bounds: 
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> 
        safe_mult(a, b) <= 99 * 99;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_correct(a, b, \result);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b) {
    uint64_t result;
    
    //@ assert a > 1 && a <= 100;
    //@ assert b > 1 && b <= 100;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    result = (a - 1) * (b - 1);
    //@ assert result == (a - 1) * (b - 1);
    
    return result;
}
