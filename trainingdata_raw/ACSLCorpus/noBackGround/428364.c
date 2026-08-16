#include <stdint.h>

/*@
    requires (0 <= (a) <= (b) <= 1000000000000000000 &&
        1 <= (x) <= 1000000000000000000);
    assigns \nothing;
    ensures 0 <= \result <= (b / x) - (a / x) + 1;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x) {
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t a_div_x;
    uint64_t b_div_x;
    uint64_t a_mod_x;

    // Precondition assertions
    //@ assert 0 <= a <= b <= 1000000000000000000;
    //@ assert 1 <= x <= 1000000000000000000;

    // Compute intermediate values
    a_div_x = a / x;
    b_div_x = b / x;
    a_mod_x = a % x;

    // Mathematical property verification
    //@ assert b_div_x >= a_div_x;

    // Calculate result
    ans = b_div_x - a_div_x;
    if (a_mod_x == 0) {
        ans = ans + 1;
    }

    // Postcondition verification
    //@ assert ans <= b_div_x - a_div_x + 1;
    //@ assert ans >= 0;

    return ans;
}
