#include <stdint.h>
/*@
    requires (0 <= (a) && (a) <= (b) && (b) <= 1000000000000000000 &&
        1 <= (x) && (x) <= 1000000000000000000);
    ensures \result <= ((b) / (x)) - ((a) / (x)) + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t tmp_div_a;
    uint64_t tmp_div_b;
    uint64_t tmp_mod_a;

    // Precondition checks
    //@ assert a <= b && b <= 1000000000000000000;
    
    tmp_div_a = a / x;
    tmp_div_b = b / x;
    tmp_mod_a = a % x;

    ans = tmp_div_b - tmp_div_a;
    //@ assert ans >= 0;

    if (tmp_mod_a == 0) {
        ans = ans + 1;
    }

    // Postcondition verification
    //@ assert ans <= ((b) / (x)) - ((a) / (x)) + 1;
    //@ assert ans >= 0;

    return ans;
}
