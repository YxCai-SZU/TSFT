#include <stdint.h>

/*@
    requires ((x) <= 0xFFFFFFFF - (y));
    ensures ((\result) == (x) + (y));
    assigns \nothing;
*/
uint32_t sum(uint32_t x, uint32_t y) {
    //@ assert x <= 0xFFFFFFFF - y;
    //@ assert x + y <= 0xFFFFFFFF;
    return x + y;
}
