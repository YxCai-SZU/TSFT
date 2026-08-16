#include <stdint.h>

/*@
    predicate is_multiple_of_three(integer x) = x % 3 == 0;
    predicate not_multiple_of_three(integer x) = x % 3 != 0;
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result >= 0;
    ensures \result <= (int)x;
    ensures is_multiple_of_three(x) ==> \result == (int)x;
    ensures not_multiple_of_three(x) ==> \result == (int)(x / 3);
*/
int32_t func(uint32_t x)
{
    int32_t result;
    //@ assert x >= 1 && x <= 100000;
    
    if (x % 3 == 0)
    {
        //@ assert (int)x <= (int)x;
        result = (int32_t)x;
    }
    else
    {
        //@ assert x / 3 <= x / 3;
        result = (int32_t)(x / 3);
    }
    
    //@ assert result >= 0;
    //@ assert result <= (int)x;
    return result;
}
