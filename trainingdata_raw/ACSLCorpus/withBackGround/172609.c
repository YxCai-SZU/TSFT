#include <stdint.h>

/*@
    predicate valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer compute_x(integer a) = a * 100 + 100;
    
    logic integer compute_result(integer a) = (a * 100 + 100) / 108;
*/

/*@
    requires valid_a(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    uint32_t x;
    uint32_t result;
    int32_t result_i32;
    
    x = a * 100 + 100;
    result = x / 108;
    
    //@ assert x == compute_x(a);
    //@ assert result == compute_result(a);
    //@ assert x == result * 108 + (x % 108);
    
    result_i32 = (int32_t)result;
    
    //@ assert result_i32 == compute_result(a);
    
    return result_i32;
}
