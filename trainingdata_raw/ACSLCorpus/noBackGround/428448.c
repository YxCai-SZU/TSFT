#include <stdint.h>

/*@
    requires 0 <= h1 <= 23;
    requires 0 <= m1 <= 59;
    requires 0 <= h2 <= 23;
    requires 0 <= m2 <= 59;
    requires 0 <= k <= 100000;
    requires h1 <= h2 && (h1 == h2 && m1 <= m2 || h1 < h2);
    ensures \result == (h2 * 60 + m2) - (h1 * 60 + m1) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t result;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) * 60 + (m1)) == h1 * 60 + m1;
    
    t1 = h1 * 60 + m1;
    //@ assert t1 == ((h1) * 60 + (m1));
    
    //@ assert ((h2) * 60 + (m2)) == h2 * 60 + m2;
    t2 = h2 * 60 + m2;
    //@ assert t2 == ((h2) * 60 + (m2));
    
    //@ assert t1 <= t2;
    result = (int32_t)t2 - (int32_t)t1 - (int32_t)k;
    //@ assert result == (int32_t)(t2 - t1 - k);
    
    return result;
}
