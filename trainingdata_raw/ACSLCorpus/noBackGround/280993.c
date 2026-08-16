#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == (((n) - (m)) % 2 == 0 ? ((n) - (m)) * 2 + 1 : ((n) - (m)) * 2 + 2);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t diff;
    int32_t result;

    diff = n - m;
    
    //@ assert diff >= 0;
    
    if (diff % 2 == 0)
    {
        //@ assert diff % 2 == 0;
        result = (int32_t)diff * 2 + 1;
    }
    else
    {
        //@ assert diff % 2 == 1;
        result = (int32_t)diff * 2 + 2;
    }
    
    return result;
}
