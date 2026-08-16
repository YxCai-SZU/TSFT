#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || \result == a - b * 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a <= b * 2)
    {
        //@ assert a <= b * 2;
        result = 0;
    }
    else
    {
        //@ assert a > b * 2;
        //@ assert a - b * 2 <= a;
        result = a - b * 2;
    }
    
    //@ assert result <= a;
    //@ assert result == 0 || result == a - b * 2;
    return result;
}
