#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    //@ assert a + (a * a) + (a * a * a) <= 1110;

    result = a + (a * a) + (a * a * a);
    return result;
}
