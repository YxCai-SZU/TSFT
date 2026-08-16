#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer mod_sum(integer a, integer b) = (a + b) % 3;

    lemma sum_bounds: \forall integer a, b; valid_range(a) && valid_range(b) ==> 1 <= a + b <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= a + b <= 200;
    
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return (int32_t)result;
}
