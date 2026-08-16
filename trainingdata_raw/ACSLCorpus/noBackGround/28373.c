#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures (n + \result) % 1000 == 0;
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t remainder;
    int32_t result;
    
    //@ assert (1 <= (n) <= 10000);
    n_unsigned = (uint32_t)n;
    remainder = n_unsigned % 1000u;
    
    if (remainder == 0u)
    {
        result = 0;
        //@ assert (n + result) % 1000 == 0;
        return result;
    }
    else
    {
        //@ assert 1000u - remainder < 1000u;
        result = (int32_t)(1000u - remainder);
        //@ assert (n + result) % 1000 == 0;
        return result;
    }
}
