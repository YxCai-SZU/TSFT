#include <stdint.h>

/*@
    requires (2 <= (A) && (A) <= 100 &&
        2 <= (B) && (B) <= 100);
    ensures \result == (A - 1) * (B - 1);
*/
uint32_t func(uint32_t A, uint32_t B)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert A - 1 > 0;
    //@ assert B - 1 > 0;
    //@ assert (A - 1) <= 99;
    //@ assert (B - 1) <= 99;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;

    result = (A - 1) * (B - 1);
    return result;
}
