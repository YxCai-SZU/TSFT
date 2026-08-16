#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100) && (1 <= (C) && (C) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    uint32_t ans;
    //@ assert (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100) && (1 <= (C) && (C) <= 100);
    
    if (A == B && B == C) {
        ans = 1;
        //@ assert ans == 1;
    } else if (A == B || A == C || B == C) {
        ans = 2;
        //@ assert ans == 2;
    } else {
        ans = 3;
        //@ assert ans == 3;
    }
    
    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
