#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result >= ((a + b + 1 <= c) ? (a + b + 1 + b) : (b + c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min_val;
    uint32_t result;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100);
    
    if (a + b + 1 <= c) {
        min_val = a + b + 1;
    } else {
        min_val = c;
    }

    //@ assert min_val == (((a) + (b) + 1 <= (c)) ? ((a) + (b) + 1) : (c));
    //@ assert min_val <= a + b + c;
    
    result = b + min_val;
    
    //@ assert b + min_val <= a + b + c;
    //@ assert result >= ((a + b + 1 <= c) ? (a + b + 1 + b) : (b + c));
    
    return result;
}
