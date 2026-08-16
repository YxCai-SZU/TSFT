#include <stdint.h>
/*@
    requires (0 <= (a) <= (b) <= 1000000000000000000 &&
        1 <= (x) <= 1000000000000000000);
    ensures \result >= (b / x) - (a / x);
    ensures \result <= (b / x) - (a / x) + 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t div_b;
    uint64_t div_a;
    uint64_t mod_a;

    // Precondition verification
    //@ assert (0 <= (a) <= (b) <= 1000000000000000000 &&         1 <= (x) <= 1000000000000000000);

    // Calculate intermediate values
    div_b = b / x;
    div_a = a / x;
    mod_a = a % x;

    // Verification of intermediate properties
    //@ assert div_b >= div_a;
    //@ assert div_b - div_a <= 18446744073709551615 - 1;

    // Calculate final result
    ans = div_b - div_a;
    if (mod_a == 0) {
        ans = ans + 1;
    }

    // Postcondition verification
    //@ assert ans >= div_b - div_a;
    //@ assert ans <= div_b - div_a + 1;

    return ans;
}
