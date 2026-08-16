#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_result(integer r) = (2 * r * 314) / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi = 314;
    int32_t result = 0;
    int32_t temp = 2 * r * pi;
    int32_t count = 0;
    
    //@ assert temp == 2 * r * 314;
    //@ assert 0 <= temp <= 2 * 100 * 314;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi - 100 * count;
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == calculate_result(r);
    return result;
}
