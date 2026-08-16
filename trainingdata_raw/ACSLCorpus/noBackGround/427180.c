#include <stdint.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == (6 - (a) - (b));
    ensures 1 <= \result <= 3;
    ensures \result != a && \result != b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert ((a) != (b));
    //@ assert (6 - (a) - (b)) >= 1;
    //@ assert (6 - (a) - (b)) <= 3;
    //@ assert (6 - (a) - (b)) != a;
    //@ assert (6 - (a) - (b)) != b;

    result = 6 - a - b;
    return result;
}
