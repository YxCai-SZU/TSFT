#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == ((a) * (1 + (a) * (1 + (a))));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 + a <= 11;
    //@ assert a * (1 + a) <= 110;
    //@ assert 1 + a * (1 + a) <= 111;
    //@ assert a * (1 + a * (1 + a)) <= 1110;

    result = a * (1 + a * (1 + a));
    return result;
}
