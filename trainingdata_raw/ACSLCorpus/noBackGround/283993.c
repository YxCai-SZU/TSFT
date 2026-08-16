#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert (1 <= (a) && (a) <= 10);
    uint32_t a2 = a * a;
    //@ assert (1 <= (a2) && (a2) <= 100);
    uint32_t a3 = a * a * a;
    //@ assert (1 <= (a3) && (a3) <= 1000);
    uint32_t result = a + a2 + a3;
    //@ assert result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    return result;
}
