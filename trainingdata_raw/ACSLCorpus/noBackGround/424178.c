#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) > (m) * 2 ? (n) - (m) * 2 : 0);
    ensures \result >= 0;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    if (n > m * 2)
    {
        //@ assert n > m * 2;
        result = n - m * 2;
    }
    else
    {
        //@ assert n <= m * 2;
        //@ assert n - m * 2 <= 0;
        result = 0;
    }
    
    //@ assert result == ((n) > (m) * 2 ? (n) - (m) * 2 : 0);
    //@ assert result >= 0;
    
    return result;
}
