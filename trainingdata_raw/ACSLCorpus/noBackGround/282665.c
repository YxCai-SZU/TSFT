#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= 1 + a && 1 + a <= 11;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * (1 + a) && a * (1 + a) <= a * 11;
    //@ assert 1 <= a * (1 + a + a * a) && a * (1 + a + a * a) <= a * 112;

    result = a * (1 + a + a * a);
    return result;
}
