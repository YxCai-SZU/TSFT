#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 16) && (1 <= (b) && (b) <= 16);
    requires ((a) * (b) <= 256);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 16);
    //@ assert (1 <= (b) && (b) <= 16);
    //@ assert ((a) * (b) <= 256);
    //@ assert a * b <= 256;

    result = a * b;
    //@ assert result == ((a) * (b));
    return result;
}
