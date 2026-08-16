#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10000);
    ensures \result >= 0 && \result < 1000;
    ensures \result == ((1000 - (a) % 1000) % 1000) || \result == 0;
*/
int32_t func(uint32_t a)
{
    uint32_t result;
    result = 1000 - a % 1000;
    
    if (result == 1000)
    {
        //@ assert result == 1000;
        return 0;
    }
    else
    {
        //@ assert result != 1000;
        //@ assert result == (1000 - a % 1000);
        return (int32_t)result;
    }
}
