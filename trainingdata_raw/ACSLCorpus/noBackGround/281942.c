#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100);
    ensures \result <= C;
    ensures \result <= B / A;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    // Variable declarations at top of scope
    uint32_t min_B_div_A;

    //@ assert A > 0;
    //@ assert B > 0;
    //@ assert C > 0;
    //@ assert B / A <= 100;

    if (B / A < C) {
        min_B_div_A = B / A;
    } else {
        min_B_div_A = C;
    }

    //@ assert min_B_div_A <= C;
    //@ assert min_B_div_A <= B / A;
    return min_B_div_A;
}
