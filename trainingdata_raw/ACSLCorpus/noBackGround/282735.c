#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
*/
uint64_t func(uint64_t a, uint64_t b) {
    uint64_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    result = a * b;
    return result;
}
