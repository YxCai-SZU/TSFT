#include <stdint.h>

/*@
    requires ((a) > 0 && (a) <= 123);
    requires ((b) > 0 && (b) <= 123);
    requires ((c) > 0 && (c) <= 123);
    requires ((d) > 0 && (d) <= 123);
    requires ((e) > 0 && (e) <= 123);
    ensures \result == (a + b + c + d + e + 5) / 5;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t result;

    //@ assert ((a) + (b) + (c) + (d) + (e)) <= 123 * 5;
    //@ assert ((a) + (b) + (c) + (d) + (e)) + 5 <= 123 * 5 + 5;

    result = (a + b + c + d + e + 5) / 5;
    return result;
}
