#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@
    requires 0 <= x <= 1000000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> is_even(x);
    ensures \result == 0 ==> !is_even(x);
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    if (x % 2 == 0)
    {
        result = 1;
        //@ assert result == 1 && is_even(x);
        return result;
    }
    else
    {
        //@ assert !is_even(x);
        result = 0;
        //@ assert result == 0 && !is_even(x);
        return result;
    }
}
