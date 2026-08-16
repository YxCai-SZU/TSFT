#include <stdint.h>

/*@ requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires ((y) % 2 == 0);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t result;
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert ((y) % 2 == 0);
    //@ assert y / 2 <= 50;
    //@ assert x + (y / 2) <= 150;
    result = x + (y / 2);
    //@ assert result == x + (y / 2);
    return result;
}
