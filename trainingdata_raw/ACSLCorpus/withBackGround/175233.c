#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10;
    predicate x_in_range(integer x) = 0 <= x && x <= 1;
    logic integer compute_result(integer a, integer x) = a * 800 - x * 200;
*/

/*@
    requires a_in_range(a);
    ensures \result == compute_result(a, a / 15);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    uint32_t x;
    int32_t result;
    
    x = a / 15;
    
    //@ assert a_in_range(a);
    //@ assert x_in_range(x);
    //@ assert a * 800 <= 8000;
    //@ assert x * 200 <= 200;
    
    result = (int32_t)(a * 800 - x * 200);
    return result;
}
