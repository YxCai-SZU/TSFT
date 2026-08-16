#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;
    
    logic integer calculate_result(integer a, integer b) =
        6 - a - b;
    
    lemma result_in_bounds:
        \forall integer a, b;
        valid_input(a, b) ==> 0 <= calculate_result(a, b) <= 4294967295;
*/

/*@
    requires valid_input(a, b);
    ensures \result == calculate_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert valid_input(a, b);
    
    //@ assert 0 <= 6 - a - b <= 4294967295;
    
    return 6 - a - b;
}
