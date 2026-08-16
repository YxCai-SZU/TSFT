#include <stdint.h>

/*@
requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
requires a <= b && b <= c;
ensures \result == c;
assigns \nothing;
*/
uint32_t func2(uint32_t a, uint32_t b, uint32_t c) {
    //@ assert a <= b && b <= c;
    return c;
}
