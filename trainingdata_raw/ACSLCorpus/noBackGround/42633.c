#include <stdint.h>

/*@
    requires ((x) > 0 && (y) > 0 && (z) > 0 &&
        (x) <= 20 && (y) <= 20 && (z) <= 20);
    ensures \result == x * y + z;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z) {
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert x > 0 && y > 0 && z > 0;
    //@ assert x <= 20 && y <= 20 && z <= 20;
    //@ assert x * y <= 400;

    result = x * y + z;
    return result;
}

int main() {
    return 0;
}
