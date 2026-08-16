#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 1000000000;
    
    logic integer compute_result(integer x) = (x - 1) / 2;
*/

/*@
    requires is_valid_input(input);
    ensures \result == compute_result(input);
    assigns \nothing;
*/
uint32_t func(uint32_t input)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert input >= 1;
    //@ assert input - 1 >= 0;
    //@ assert (input - 1) / 2 <= 2147483647;
    
    result = (input - 1) / 2;
    
    //@ assert result == compute_result(input);
    
    return result;
}

/*@
    lemma no_underflow: \forall integer x; is_valid_input(x) ==> x - 1 >= 0;
    lemma no_overflow: \forall integer x; is_valid_input(x) ==> (x - 1) / 2 <= 2147483647;
*/
