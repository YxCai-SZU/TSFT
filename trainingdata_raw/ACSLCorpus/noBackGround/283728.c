#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) < (m) ? 0 : (n) - (m));
    ensures n < m ==> \result == 0;
    ensures n >= m ==> \result == (int)(n - m);
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    
    if (n < m)
    {
        //@ assert n < m;
        result = 0;
    }
    else
    {
        //@ assert n >= m;
        //@ assert n - m <= 99;
        result = (int32_t)(n - m);
    }
    
    return result;
}
