#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == (((a) + 2) * 100 + 7) || \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 10);
    
    if (a + 2 > 10)
    {
        result = 0;
    }
    else
    {
        //@ assert a + 2 <= 12;
        //@ assert (a + 2) * 100 <= 1200;
        result = (int32_t)((a + 2) * 100 + 7);
    }
    
    //@ assert result == (((a) + 2) * 100 + 7) || result == 0;
    return result;
}
