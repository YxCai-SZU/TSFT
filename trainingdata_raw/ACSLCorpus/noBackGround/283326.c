#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 50 &&
        0 <= (b) && (b) <= 50 &&
        0 <= (c) && (c) <= 50);
    ensures \result >= 0 && \result <= 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert (0 <= (a) && (a) <= 50 &&         0 <= (b) && (b) <= 50 &&         0 <= (c) && (c) <= 50);
    //@ assert 0 <= a + b && a + b <= 100;

    if (c > a + b)
    {
        result = 2;
    }
    else if (a + b > c)
    {
        result = 1;
    }
    else
    {
        //@ assert a + b == c;
        //@ assert 0 >= 0 && 0 <= 2;
        result = 0;
    }

    //@ assert result >= 0 && result <= 2;
    return result;
}
