#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * 2 + 100 - ((b) + 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    uint32_t d;
    int32_t result;

    c = a * 2 + 100;
    d = b + 1;

    //@ assert c == a * 2 + 100;
    //@ assert d == b + 1;

    result = (int32_t)(c - d);
    return result;
}
