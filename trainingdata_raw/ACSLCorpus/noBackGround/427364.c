#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t c500;
    uint32_t r500;
    uint32_t c5;
    uint32_t r5;
    uint32_t result;

    c500 = x / 500;
    r500 = x % 500;

    c5 = r500 / 5;
    r5 = r500 % 5;

    //@ assert r500 == x % 500;
    //@ assert r5 == r500 % 5;

    result = c500 * 1000 + c5 * 5;
    return result;
}
