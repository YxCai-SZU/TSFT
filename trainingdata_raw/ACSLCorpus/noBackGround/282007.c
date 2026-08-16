#include <stdint.h>

/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    ensures \result == ((a + b) % 24);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert 0 <= a <= 23;
    //@ assert 0 <= b <= 23;
    //@ assert 0 <= a + b <= 46;

    result = (a + b) % 24;
    return result;
}
