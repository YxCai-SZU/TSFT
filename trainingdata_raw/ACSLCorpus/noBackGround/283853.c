#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures 0 <= \result <= 100000;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t result = 0;
    uint32_t i = 1;
    uint32_t current_base = 1;
    
    /*@
        loop invariant 1 <= i <= x;
        loop invariant 1 <= current_base <= i;
        loop invariant 0 <= result <= i;
        loop invariant result <= 100000;
        loop assigns i, current_base, result;
        loop variant x - i;
    */
    while (i < x)
    {
        if (current_base >= i)
        {
            //@ assert current_base >= i;
            result += 1;
            current_base = 1;
        }
        else
        {
            //@ assert current_base < i;
            current_base += 1;
        }
        
        i += 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 100000;
    return result;
}
