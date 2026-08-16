#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_in_range(integer result, integer a, integer b) = 
        result >= 0 && result <= a * 100 + b;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_in_range(\result, a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t tmp1;
    uint32_t tmp2;
    uint32_t tmp3;
    int32_t result;
    
    //@ assert a + b / 2 <= 200;
    
    //@ assert b % 2 <= 1;
    
    tmp1 = a + b / 2;
    tmp2 = b % 2;
    tmp3 = tmp1 + tmp2;
    result = (int32_t)tmp3;
    
    //@ assert result <= (int32_t)a * 100 + (int32_t)b;
    
    return result;
}
