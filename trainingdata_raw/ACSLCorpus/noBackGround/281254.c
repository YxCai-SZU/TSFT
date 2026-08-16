#include <stdint.h>

/*@
    requires (0 <= (x) && (x) < 1000000000000000000 &&
        0 <= (y) && (y) < 1000000000000000000 &&
        (x) * (y) < 1000000000000000000);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y) {
    //@ assert (0 <= (x) && (x) < 1000000000000000000 &&         0 <= (y) && (y) < 1000000000000000000 &&         (x) * (y) < 1000000000000000000);
    return x * y;
}
