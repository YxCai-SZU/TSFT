#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10;
    
    logic integer func_spec(integer a) = a + a * a + a * a * a;
*/

/*@
    requires a_in_range(a);
    ensures \result == func_spec(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert a_in_range(a);
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == func_spec(a);
    return result;
}
