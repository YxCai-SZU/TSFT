#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == ((a) + (c)) || \result == ((b) + (d)) || 
            \result == ((a) + (d)) || \result == ((b) + (c));
    ensures \result >= ((a) + (c)) && \result >= ((b) + (d)) && 
            \result >= ((a) + (d)) && \result >= ((b) + (c));
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t m1;
    uint32_t m2;
    uint32_t m3;
    uint32_t m4;
    uint32_t max_val;

    m1 = a + c;
    m2 = b + d;
    m3 = a + d;
    m4 = b + c;

    max_val = m1;
    //@ assert max_val == m1;
    
    if (m2 > max_val)
    {
        max_val = m2;
        //@ assert max_val == m2;
    }
    //@ assert max_val >= m1 && max_val >= m2;
    
    if (m3 > max_val)
    {
        max_val = m3;
        //@ assert max_val == m3;
    }
    //@ assert max_val >= m1 && max_val >= m2 && max_val >= m3;
    
    if (m4 > max_val)
    {
        max_val = m4;
        //@ assert max_val == m4;
    }
    //@ assert max_val >= m1 && max_val >= m2 && max_val >= m3 && max_val >= m4;
    
    //@ assert max_val == m1 || max_val == m2 || max_val == m3 || max_val == m4;
    
    return max_val;
}
