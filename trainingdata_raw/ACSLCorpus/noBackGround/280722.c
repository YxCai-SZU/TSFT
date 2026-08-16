#include <stdint.h>

/*@
    requires 1 <= A && A <= 100;
    requires 1 <= B && B <= 100;
    requires 1 <= C && C <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (A == B && B == C);
    ensures \result == 2 ==> ((A == B && B != C) || (A == C && A != B) || (B == C && A != B));
    ensures \result == 3 ==> (A != B && B != C && A != C);
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    uint32_t ans;
    
    if (A == B && B == C) {
        ans = 1;
        //@ assert A == B && B == C;
    } else if (A != B && B != C && A != C) {
        ans = 3;
        //@ assert A != B && B != C && A != C;
    } else {
        ans = 2;
        //@ assert (A == B && B != C) || (A == C && A != B) || (B == C && A != B);
    }
    
    return ans;
}
