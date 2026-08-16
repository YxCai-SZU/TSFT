#include <stdint.h>

/*@
    predicate is_in_range(integer a) = 1 <= a && a <= 10;
    
    logic integer func_result(integer a) = 
        a <= 3 ? 5 : 0;
*/

/*@
    requires is_in_range(a);
    ensures \result == func_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert is_in_range(a);
    
    if (a <= 3)
    {
        //@ assert a <= 3;
        result = 5;
    }
    else
    {
        //@ assert a > 3;
        result = 0;
    }
    
    //@ assert result == func_result(a);
    return result;
}
