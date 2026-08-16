#include <stdint.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
    
    logic integer func_result(integer x) =
        (x % 2 == 0) ? 1 : ((x / 2 + 1) * 2) / x;
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == func_result(x);
    ensures (x % 2 == 0) ==> \result == 1;
    ensures (x % 2 != 0) ==> \result == ((x / 2 + 1) * 2) / x;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    
    if (x % 2 == 0)
    {
        result = 1;
    }
    else
    {
        //@ assert x / 2 + 1 <= x;
        result = (int32_t)(((x / 2 + 1) * 2) / x);
    }
    
    return result;
}
