#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= 200;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert b / 100 <= 1;
    //@ assert a + b / 100 <= 101;
    
    result = a + b / 100;
    
    if (result >= 100)
    {
        return (int32_t)(result / 100);
    }
    else
    {
        return 0;
    }
}
