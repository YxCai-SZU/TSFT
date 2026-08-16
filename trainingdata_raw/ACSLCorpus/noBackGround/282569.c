#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;
    uint32_t a_squared;
    uint32_t a_cubed;

    //@ assert (1 <= (a) && (a) <= 10);
    result = a;

    //@ assert a * a <= 100;
    a_squared = a * a;

    //@ assert a * a * a <= 1000;
    a_cubed = a * a * a;

    result += a_squared;
    result += a_cubed;

    //@ assert result == a + a * a + a * a * a;
    return result;
}
