#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 10) && (0 <= (b) && (b) <= 10);
    ensures \result == ((a) * (a) + (b) * (b) + 2 * (a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t aa;
    uint32_t bb;
    uint32_t twoab;
    uint32_t result;

    //@ assert ((a) * (a) <= 100);
    aa = a * a;

    //@ assert ((b) * (b) <= 100);
    bb = b * b;

    //@ assert (2 * (a) * (b) <= 200);
    twoab = 2 * a * b;

    result = aa + bb + twoab;
    //@ assert result == ((a) * (a) + (b) * (b) + 2 * (a) * (b));
    return result;
}
