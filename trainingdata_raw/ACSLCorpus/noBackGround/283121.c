#include <stdint.h>
/*@
    requires
        (0 <= (a) && (a) <= (b) && (b) <= 1000000000000000000 &&
        1 <= (x) && (x) <= 1000000000000000000);
    ensures
        \result <= (b / x) - (a / x) + 1 &&
        \result >= 0;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t cnt = 0;
    uint64_t tmp_mod = 0;
    uint64_t adjustment = 0;

    //@ assert (0 <= (a) && (a) <= (b) && (b) <= 1000000000000000000 &&         1 <= (x) && (x) <= 1000000000000000000);
    //@ assert a / x <= b / x;

    tmp_mod = a % x;
    if (tmp_mod == 0) {
        adjustment = 1;
    } else {
        adjustment = 0;
    }
    cnt = (b / x) - (a / x) + adjustment;

    //@ assert cnt <= (b / x) - (a / x) + 1;
    //@ assert cnt >= 0;
    return cnt;
}
