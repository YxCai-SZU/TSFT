#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = x <= 1;

    logic integer func_spec(integer x) = 1 - x;

    lemma func_lemma: \forall integer x; is_valid_input(x) ==> func_spec(x) >= 0;
*/

/*@
    requires is_valid_input(x);
    ensures \result == func_spec(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t y;
    
    //@ assert x <= 1;
    
    if (x == 0) {
        y = 1;
    } else {
        y = 0;
    }
    
    //@ assert y == 1 - x;
    
    return y;
}
