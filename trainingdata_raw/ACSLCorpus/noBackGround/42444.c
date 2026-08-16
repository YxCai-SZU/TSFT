#include <stdint.h>

/*@
    requires 0 <= x <= 8;
    requires 0 <= y <= 8;
    ensures \result == x * y;
    ensures \result <= 64;
*/
uint32_t non_linear_arith_test(uint32_t x, uint32_t y) {
    uint32_t result;
    //@ assert 0 <= x <= 8 && 0 <= y <= 8;
    //@ assert x * y <= 64;
    result = x * y;
    return result;
}

int main() {
    return 0;
}
