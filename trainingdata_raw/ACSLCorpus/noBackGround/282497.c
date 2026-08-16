#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> x % 100 <= 5 * (x / 100);
    ensures \result == 0 ==> x % 100 > 5 * (x / 100);
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t m;
    int32_t result;
    
    n = x / 100;
    m = x % 100;
    
    //@ assert n >= 0 && n <= 1000;
    //@ assert m >= 0 && m <= 99;
    //@ assert 5 * n <= 5000;
    
    if (m <= 5 * n)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    return result;
}
