#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((x) % 100) <= (5 * (((x) / 100)));
    ensures \result == 0 ==> ((x) % 100) > (5 * (((x) / 100)));
*/
uint32_t func(uint32_t x)
{
    uint32_t d;
    uint32_t m;
    uint32_t c;
    uint32_t ans;

    d = x / 100;
    m = x % 100;
    
    //@ assert d <= 1000;
    //@ assert 5 * d <= 5000;
    
    c = 5 * d;
    
    if (m <= c)
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }
    
    return ans;
}
