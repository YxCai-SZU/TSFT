#include <stdint.h>

/*@
    requires 0 <= h1 <= 23;
    requires 0 <= m1 <= 59;
    requires 0 <= h2 <= 23;
    requires 0 <= m2 <= 59;
    requires 0 <= k <= 60;
    requires h1 < h2 || (h1 == h2 && m1 <= m2);
    ensures \result == (h2 - h1) * 60 + m2 - m1 - k;
    assigns \nothing;
*/
int32_t func(uint8_t h1, uint8_t m1, uint8_t h2, uint8_t m2, uint8_t k)
{
    int32_t d;
    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59) && (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    
    d = 60 * ((int32_t)h2 - (int32_t)h1);
    //@ assert d == (h2 - h1) * 60;
    
    d += (int32_t)m2;
    //@ assert d == (h2 - h1) * 60 + m2;
    
    d -= (int32_t)m1;
    //@ assert d == (h2 - h1) * 60 + m2 - m1;
    
    d -= (int32_t)k;
    //@ assert d == (h2 - h1) * 60 + m2 - m1 - k;
    
    return d;
}
