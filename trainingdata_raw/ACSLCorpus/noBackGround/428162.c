#include <stdint.h>

/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    ensures \result == ((a + b) % 24);
    ensures 0 <= \result <= 23;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;

    sum = a + b;
    result = sum;

    //@ assert sum == a + b;

    if (result >= 24) {
        result = result - 24;
    }

    //@ assert result == ((a + b) % 24);

    return result;
}
