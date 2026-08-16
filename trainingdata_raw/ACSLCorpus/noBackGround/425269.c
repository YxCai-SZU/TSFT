#include <stdint.h>

/*@
    requires (0 <= (a) <= (b) <= 1000000000000000000 &&
        1 <= (x) <= 1000000000000000000);
    ensures \result >= 0;
    ensures \result <= (b / x) - (a / x) + 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t a_div_x;
    uint64_t b_div_x;
    uint64_t a_mod_x;

    // Precondition assertions
    //@ assert 0 <= a <= b <= 1000000000000000000;
    //@ assert 1 <= x <= 1000000000000000000;

    // Prevent overflow in calculations
    //@ assert a <= 1000000000000000000;
    //@ assert b <= 1000000000000000000;
    //@ assert x <= 1000000000000000000;

    // Division monotonicity lemma application
    //@ assert b / x >= a / x;

    // Compute intermediate values
    a_div_x = a / x;
    b_div_x = b / x;
    a_mod_x = a % x;

    // Compute final answer
    ans = b_div_x - a_div_x;
    if (a_mod_x == 0) {
        ans = ans + 1;
    }

    // Postcondition verification
    //@ assert ans >= 0;
    //@ assert ans <= b_div_x - a_div_x + 1;

    return ans;
}
