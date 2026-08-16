#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 12 &&
        1 <= b && b <= 31;

    logic integer func_result(integer a, integer b) =
        a <= b ? a : a - 1;

    lemma result_bound: \forall integer a, b;
        valid_input(a, b) ==> func_result(a, b) <= a;
*/

/*@
    requires valid_input(a, b);
    ensures \result <= a;
    ensures \result == func_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    //@ assert valid_input(a, b);
    
    if (a <= b) {
        result = a;
        //@ assert result == a;
    } else {
        result = a - 1;
        //@ assert result == a - 1;
    }
    
    //@ assert result <= a;
    //@ assert result == func_result(a, b);
    return result;
}
