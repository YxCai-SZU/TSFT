#include <stdint.h>

/*@ requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
      (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
      (y) + (z) <= (x));
    ensures \result <= x;
    ensures \result == (x - z) / (y + z);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t res;
    //@ assert 1 <= x && 1 <= y && 1 <= z;
    //@ assert y + z <= x;
    res = (x - z) / (y + z);
    //@ assert res <= x;
    //@ assert res == (x - z) / (y + z);
    return res;
}
