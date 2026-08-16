#include <stdint.h>

/*@
    requires (0 <= (a) <= 23 && 0 <= (b) <= 23 &&
        (a) < 4294967295 && (b) < 4294967295);
    ensures \result == (((a) + (b)) % 24);
    ensures 0 <= \result <= 23;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    uint32_t result;

    //@ assert (0 <= (a) <= 23 && 0 <= (b) <= 23 &&         (a) < 4294967295 && (b) < 4294967295);
    c = a + b;
    //@ assert c == a + b;
    result = c % 24;
    //@ assert result == c % 24;
    //@ assert result == (((a) + (b)) % 24);
    return result;
}
