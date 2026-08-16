#include <stdint.h>

/*@
    requires n > 0;
    ensures \result <= n;
*/
uint32_t mod_example(uint32_t x, uint32_t n) {
    //@ assert n > 0;
    uint32_t result;
    result = x % n;
    //@ assert result <= n;
    return result;
}
