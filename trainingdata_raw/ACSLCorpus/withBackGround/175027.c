#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    predicate distinct(integer a, integer b) = a != b;
    logic integer remaining_sum(integer a, integer b) = 6 - a - b;
*/

/*@
    requires valid_range(a) && valid_range(b) && distinct(a, b);
    ensures \result == remaining_sum(a, b);
    ensures valid_range(\result);
    ensures distinct(\result, a) && distinct(\result, b);
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b) && distinct(a, b);
    
    if (a == 1)
    {
        if (b == 2)
        {
            result = 3;
        }
        else
        {
            result = 2;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            result = 3;
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        if (b == 1)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }
    }
    
    //@ assert valid_range(result);
    //@ assert distinct(result, a) && distinct(result, b);
    //@ assert result == remaining_sum(a, b);
    
    return result;
}
