#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((b) % (a) == 0 ? (b) / (a) : -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at the top of scope
    uint32_t remainder;
    uint32_t quotient;
    int32_t return_value;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    remainder = b % a;
    
    if (remainder == 0)
    {
        quotient = b / a;
        //@ assert quotient <= 100;
        return_value = (int32_t)quotient;
    }
    else
    {
        return_value = -1;
    }
    
    //@ assert return_value == ((b) % (a) == 0 ? (b) / (a) : -1);
    return return_value;
}
