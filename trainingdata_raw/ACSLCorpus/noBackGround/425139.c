#include <stdint.h>

/*@
    requires x <= 16 && y <= 16;
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t x, uint32_t y) {
    uint32_t ans;
    //@ assert ((x) <= 16 && (y) <= 16);
    //@ assert (uint64_t)x * y <= 256;
    ans = x * y;
    return ans;
}
