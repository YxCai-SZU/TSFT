#include <stdint.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t res;

    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    //@ assert a + b - 1 <= 100 + 100 - 1;
    //@ assert a * b >= a + b - 1;

    res = a * b - (a + b - 1);
    //@ assert res == ((a) * (b) - ((a) + (b) - 1));
    return res;
}
