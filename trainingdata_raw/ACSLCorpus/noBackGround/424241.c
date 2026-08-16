#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a) + (b) >= (c) ? ((a) + (b) - (c)) / 2 : 0);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    if (a + b >= c)
    {
        //@ assert a + b >= c;
        //@ assert a + b <= 200;
        //@ assert a + b - c <= 200;
        //@ assert (a + b - c) / 2 <= 100;
        result = (a + b - c) / 2;
    }
    else
    {
        result = 0;
    }

    return result;
}
