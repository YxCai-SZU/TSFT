#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result <= b * c + d;
    ensures \result <= a * c + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t result;

    //@ assert b * c <= 10000 * 10000;
    //@ assert a * c <= 10000 * 10000;
    //@ assert b * c + d <= 10000 * 10000 + 10000;
    //@ assert a * c + d <= 10000 * 10000 + 10000;
    //@ assert b * c + d >= 1;
    //@ assert a * c + d >= 1;

    if (b * c < a * c) {
        result = b * c + d;
    } else {
        result = a * c + d;
    }

    return result;
}
