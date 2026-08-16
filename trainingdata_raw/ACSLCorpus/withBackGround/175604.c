#include <stdint.h>

/*@
    predicate valid_input(integer a) = 3 <= a <= 100;
    logic integer compute_result(integer a) = 180 * (a - 2);
*/

/*@
    requires valid_input(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert 180 * ((integer)a - 2) == 180 * ((integer)a - 2);
    //@ assert 180 * ((integer)a - 2) >= 0 && 180 * ((integer)a - 2) <= 180 * 98;
    
    result = 180 * ((int32_t)a - 2);
    return result;
}
