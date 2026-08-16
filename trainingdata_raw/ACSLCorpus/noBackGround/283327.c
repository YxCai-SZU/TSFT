#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((m) * 2 <= (n) ? (m) + ((n) - (m) * 2) / 4 : (n) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result;
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (m * 2 <= n)
    {
        result = m + (n - m * 2) / 4;
        //@ assert result == ((m) * 2 <= (n) ? (m) + ((n) - (m) * 2) / 4 : (n) / 2);
    }
    else
    {
        result = n / 2;
        //@ assert result == ((m) * 2 <= (n) ? (m) + ((n) - (m) * 2) / 4 : (n) / 2);
    }
    
    return result;
}
