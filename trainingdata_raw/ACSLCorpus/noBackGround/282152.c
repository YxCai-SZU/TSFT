#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
    ensures \result <= a + b + c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    if (c > a + b + 1)
    {
        result = a + b + 1 + b;
    }
    else
    {
        result = b + c;
    }

    //@ assert result <= a + b + c;

    return result;
}
