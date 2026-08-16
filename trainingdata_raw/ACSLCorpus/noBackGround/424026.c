#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert a > 1 && a <= 100;
    //@ assert b > 1 && b <= 100;
    //@ assert (a - 1) * (b - 1) >= 1;
    //@ assert (a - 1) * (b - 1) <= 9801;
    //@ assert (a - 1) * (b - 1) <= 10000;

    res = (a - 1) * (b - 1);
    return res;
}
