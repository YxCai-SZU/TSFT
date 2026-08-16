#include <stdint.h>
#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Declare all variables at the top
    uint32_t result;

    //@ assert a * b <= 100 * 100;
    //@ assert a * b + 1 <= 101 * 101;
    //@ assert a * b + 1 <= UINT32_MAX;

    result = (a * b + 1) / 2;
    return result;
}
