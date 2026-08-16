#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t min_divisor;
    uint64_t p;
    uint64_t p_minus_1;
    uint64_t ans;

    min_divisor = n <= m ? n : m;
    p = 1;
    p_minus_1 = 0;

    /*@
        loop invariant 1 <= p && p <= min_divisor + 1;
        loop invariant p_minus_1 <= p - 1;
        loop invariant (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
        loop assigns p, p_minus_1;
        loop variant min_divisor - p;
    */
    while (p < min_divisor) {
        if (n % p == 0 && m % p == 0) {
            p_minus_1 = p;
        }
        p = p + 1;
    }

    if (p_minus_1 == 0) {
        ans = 0;
    } else {
        ans = m / p_minus_1;
    }

    //@ assert ans <= m;
    return ans;
}
