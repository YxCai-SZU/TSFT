#include <stdint.h>

/*@
    requires (0 <= (a) < 10);
    requires (0 <= (b) < 10);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert (0 <= (a) < 10);
    //@ assert (0 <= (b) < 10);
    //@ assert ((a) * (b)) < 100;

    res = a * b;
    //@ assert res == ((a) * (b));
    return res;
}
