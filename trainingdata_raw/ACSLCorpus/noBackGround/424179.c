#include <stdint.h>

/*@
    requires 0 <= a <= 100;
    requires 2 <= b <= 1000;
    requires ((b) % 2 == 0);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result == b || \result == b/2 || \result == 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    if (a >= 13)
    {
        result = b;
        //@ assert result == b;
    }
    else if (a >= 6)
    {
        //@ assert b/2 <= b;
        result = b / 2;
        //@ assert result == b/2;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }
    
    return result;
}
