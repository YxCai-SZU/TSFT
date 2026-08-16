#include <stdint.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    logic integer func_res(integer x) = (x == 0) ? 1 : 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures \result == func_res(x);
    ensures is_zero(x) ==> \result == 1;
    ensures is_one(x) ==> \result == 0;
*/
int32_t func(uint32_t x)
{
    int32_t res;
    
    if (x == 0)
    {
        //@ assert is_zero(x);
        res = 1;
    }
    else
    {
        //@ assert is_one(x);
        res = 0;
    }
    
    return res;
}
