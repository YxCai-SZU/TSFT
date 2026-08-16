#include <stdint.h>

/*@
    requires ((a) <= 10000 && (b) <= 10000);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    result = a * b;
    //@ assert result == ((a) * (b));

    return result;
}
