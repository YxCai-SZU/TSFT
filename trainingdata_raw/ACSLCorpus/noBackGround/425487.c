#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((a + b) % 2) == 0);
    ensures \result == 0 ==> (((a + b) % 2) != 0);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t is_even_bool;
    uint32_t result;
    uint32_t x;
    
    sum = a + b;
    is_even_bool = (sum % 2) == 0;
    
    if (is_even_bool)
    {
        result = (a + b) >> 1;
        x = 1;
        //@ assert (((a + b) % 2) == 0);
        return (int32_t)x;
    }
    else
    {
        result = (a + b) >> 1;
        x = 0;
        //@ assert (((a + b) % 2) != 0);
        return (int32_t)x;
    }
}
