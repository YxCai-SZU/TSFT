#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result == ((c) < (a) + (b) + 1 ? (a) + (b) + (c) : 2 * ((a) + (b) + 1) - 1);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    if (c < a + b + 1)
    {
        //@ assert a + b + c <= 300;
        result = a + b + c;
    }
    else
    {
        //@ assert 2 * (a + b + 1) - 1 <= 401;
        result = 2 * (a + b + 1) - 1;
    }

    return result;
}
