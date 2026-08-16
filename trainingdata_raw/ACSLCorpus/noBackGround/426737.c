#include <stdint.h>

/*@
    requires ((x) <= 8 && (y) <= 8);
    ensures ((x) * (y) <= 1000);
*/
void bound_check(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;
}

/*@
    requires ((x) <= 8 && (y) <= 8) && z <= 8;
    ensures ((x) * (y) <= 1000);
    ensures ((x) * (y) * (z) <= 10000);
*/
void nonlinear_arith_check(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x * y <= 100;
    //@ assert x * y * z <= 10000;
}

/*@
    ensures x * (y + z) == x * y + x * z;
*/
void distributivity_check(int x, int y, int z) {
    //@ assert x * (y + z) == x * y + x * z;
}
