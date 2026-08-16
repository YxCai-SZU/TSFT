#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) + (c)) || \result == ((b) + (d)) || 
            \result == ((a) + (d)) || \result == ((b) + (c));
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s4;
    uint32_t max_value;

    s1 = a + c;
    s2 = b + d;
    s3 = a + d;
    s4 = b + c;

    max_value = s1;

    if (s2 > max_value)
    {
        max_value = s2;
    }

    //@ assert max_value == s1 || max_value == s2;

    if (s3 > max_value)
    {
        max_value = s3;
    }

    //@ assert max_value == s1 || max_value == s2 || max_value == s3;

    if (s4 > max_value)
    {
        max_value = s4;
    }

    //@ assert max_value == s1 || max_value == s2 || max_value == s3 || max_value == s4;

    return max_value;
}
