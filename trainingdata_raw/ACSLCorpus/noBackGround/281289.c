#include <stdint.h>

/*@
    requires (1 <= (h) <= 20 && 1 <= (w) <= 20);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (h * w) % 2 == 0;
    ensures \result == 1 ==> (h * w) % 2 != 0;
*/
int32_t func(uint32_t h, uint32_t w) {
    uint32_t product;
    int32_t result;

    //@ assert (1 <= (h) <= 20 && 1 <= (w) <= 20);
    //@ assert ((h) * (w)) <= 400;
    product = h * w;

    if (product % 2 == 0) {
        result = 0;
    } else {
        result = 1;
    }

    return result;
}
