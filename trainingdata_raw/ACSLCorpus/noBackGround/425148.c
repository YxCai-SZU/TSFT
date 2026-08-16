#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t x;
    int32_t result;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    x = c + b - a;

    if (x < 0)
    {
        result = 0;
    }
    else
    {
        result = x;
    }

    //@ assert result >= 0;
    //@ assert result <= a - b + c;
    return result;
}
