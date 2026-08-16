#include <stdint.h>
/*@
    requires (2 <= (A) <= 100) && (2 <= (B) <= 100);
    ensures \result == (((A) - 1) * ((B) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 2 <= A <= 100;
    //@ assert 2 <= B <= 100;
    //@ assert A - 1 >= 1;
    //@ assert B - 1 >= 1;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;

    result = (A - 1) * (B - 1);
    //@ assert result == (((A) - 1) * ((B) - 1));
    return result;
}
