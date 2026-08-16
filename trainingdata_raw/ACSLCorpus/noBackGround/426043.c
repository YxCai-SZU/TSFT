#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Variable declarations at scope top
    uint64_t a2;
    uint64_t a3;
    uint64_t result;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert ((a) * (a)) <= 100;
    //@ assert ((a) * (a) * (a)) <= 1000;

    a2 = a * a;
    a3 = a * a * a;
    result = a + a2 + a3;

    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}
