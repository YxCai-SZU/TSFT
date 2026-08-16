#include <stdint.h>

/*@
    predicate valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer compute_result(integer a) = a * 100 + 100;
*/

/*@
    requires valid_a(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    uint32_t r;
    
    //@ assert valid_a(a);
    r = a * 100;
    
    //@ assert r == a * 100;
    
    return (int32_t)(r + 100);
}
