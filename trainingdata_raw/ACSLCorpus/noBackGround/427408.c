#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert a + (a * a) + (a * a * a) >= a;
    //@ assert a + (a * a) + (a * a * a) <= 18446744073709551615;
    //@ assert a * a <= 18446744073709551615 / a;
    //@ assert a * a * a <= 18446744073709551615 / a;

    result = a + (a * a) + (a * a * a);
    //@ assert result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    return result;
}
