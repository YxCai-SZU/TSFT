#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((n) > (m) ? 0 : ((m) - (n)) * 2 - 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n > m)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert m >= n;
        //@ assert (m - n) * 2 <= 40;
        result = (int32_t)((m - n) * 2 - 1);
        //@ assert result == (m - n) * 2 - 1;
    }
    
    return result;
}
