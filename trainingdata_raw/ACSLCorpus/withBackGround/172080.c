#include <stdint.h>

/*@
    predicate valid_range(integer x) = 2 <= x <= 100;

    logic integer target_expr(integer a, integer b) = a * b - a - b + 1;

    lemma expr_positive: \forall integer a, b; valid_range(a) && valid_range(b) ==> target_expr(a, b) > 0;
    lemma expr_non_overflow: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000;
    lemma expr_non_underflow: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b - a - b + 1 >= 1;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == target_expr(a, b);
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Declare all variables at the top
    uint32_t result;

    // Precondition assertions
    //@ assert valid_range(a);
    //@ assert valid_range(b);

    // Mathematical properties
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b + 1 > 0;
    //@ assert a * b <= 10000;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -99;
    //@ assert a * b - a - b + 1 >= 1;

    // Final computation
    result = a * b - a - b + 1;
    
    // Postcondition verification
    //@ assert result == target_expr(a, b);
    //@ assert result > 0;
    
    return result;
}
