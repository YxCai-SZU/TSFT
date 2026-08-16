#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    ensures \result >= 1 && \result <= 100;
*/
uint64_t func(uint64_t a, uint64_t b) {
    uint64_t sum;
    uint64_t result;

    sum = a + b;
    result = (sum + 1) / 2;

    //@ assert result == (a + b + 1) / 2;
    //@ assert result >= 1;
    //@ assert result <= 100;

    return result;
}
