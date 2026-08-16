#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    result = c - a + b;
    //@ assert result == ((c) - (a) + (b));
    //@ assert result <= c;
    if (result < 0) {
        result = 0;
    }
    //@ assert result >= 0;
    //@ assert result <= c;
    return result;
}
