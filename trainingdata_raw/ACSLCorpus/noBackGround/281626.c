#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((((n)) * ((n))) * 3);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) <= 10000;
    //@ assert ((((n)) * ((n))) * 3) <= 30000;

    result = n * n * 3;
    //@ assert result == ((((n)) * ((n))) * 3);
    return result;
}
