#include <stdint.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a * b <= 100 * 100;
    //@ assert a + b - 1 <= 100 + 100 - 1;
    //@ assert a * b >= a + b - 1;

    result = a * b - (a + b - 1);
    return result;
}
