#include <stdint.h>

/*@
    requires (0 <= (a) <= 123) && (0 <= (b) <= 123) && (0 <= (c) <= 123) && (0 <= (d) <= 123) && (0 <= (e) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (b - a - 1) + (d - c - 1);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t result = 0;
    
    //@ assert b > a;
    //@ assert d > c;
    //@ assert b - a - 1 <= 122;
    //@ assert (b - a - 1) + (d - c - 1) <= 244;
    
    result += b - a - 1;
    result += d - c - 1;
    
    return result;
}
