#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0);
    ensures \result <= (x / 11) * 2 + 2;
    ensures \result == (x / 11) * 2 + (x % 11 + 5) / 6;
*/
uint32_t func(uint32_t x) {
    uint32_t n1;
    uint32_t n2;
    uint32_t result;

    n1 = x / 11;
    n2 = x % 11;
    result = n1 * 2;

    //@ assert ((result) >= 0);
    //@ assert result <= (x / 11) * 2 + 2;

    if (n2 > 0 && n2 <= 6) {
        result += 1;
    } else if (n2 > 6) {
        result += 2;
    }

    //@ assert result == (x / 11) * 2 + (x % 11 + 5) / 6;
    return result;
}
