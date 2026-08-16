#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n <= m;
    ensures \result == 1 ==> n > m;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t res;
    
    if (n <= m)
    {
        //@ assert n <= m;
        res = 0;
    }
    else
    {
        //@ assert n > m;
        res = 1;
    }
    
    return res;
}
