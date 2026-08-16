#include <stdint.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A + B || \result == C + D;
    ensures \result >= A + B;
    ensures \result >= C + D;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
    uint32_t x;
    uint32_t y;
    uint32_t ans;

    //@ assert A + B <= 20000;
    //@ assert C + D <= 20000;

    x = A + B;
    y = C + D;

    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }

    return ans;
}
