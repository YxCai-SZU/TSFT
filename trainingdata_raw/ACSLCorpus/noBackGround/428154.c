#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * ((a) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert a + 1 <= 101;
    //@ assert a * (a + 1) <= 10100;

    result = a * (a + 1) / 2;
    //@ assert result == ((a) * ((a) + 1) / 2);
    return result;
}
