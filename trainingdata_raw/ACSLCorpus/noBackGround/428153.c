#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == a + c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a + b < b + c) {
        if (a + b < a + c) {
            result = a + b;
        } else {
            result = a + c;
        }
    } else {
        if (b + c < a + c) {
            result = b + c;
        } else {
            result = a + c;
        }
    }

    //@ assert result <= a + b + c;
    //@ assert result == a + b || result == b + c || result == a + c;
    
    return result;
}
