#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t d) {
    // Variable declarations at the top
    uint32_t two_d;
    uint32_t numerator;
    uint32_t ans;

    // Precondition verification
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= d <= 20;

    two_d = 2 * d;
    //@ assert two_d >= 2;
    //@ assert two_d <= 40;

    numerator = n + two_d - 1;
    //@ assert numerator <= 40 + 40 - 1;

    ans = numerator / two_d;
    //@ assert ans >= 0;
    //@ assert ans <= (40 + 40 - 1) / 2;
    //@ assert ans <= n;

    return (int32_t)ans;
}
