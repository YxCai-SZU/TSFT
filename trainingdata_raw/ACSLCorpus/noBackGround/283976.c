#include <stdint.h>

/*@
    requires a < 0x80000000;
    requires b > 0;
    ensures \result == a / b;
    ensures \result <= a;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert a >= 0 && a < 0x80000000;
    //@ assert b > 0;
    //@ assert a / b <= a;

    ans = a / b;
    return ans;
}
