#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 1000000000 &&
        0 <= (B) && (B) <= 1000000000 &&
        0 <= (C) && (C) <= 1000000000);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (A + B == C || A + C == B || B + C == A);
    ensures \result == 2 ==> 
        (A + B > C && A + C > B && B + C > A) && 
        !(A + B == C || A + C == B || B + C == A);
    ensures \result == 3 ==> (A + B <= C || A + C <= B || B + C <= A);
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C) {
    // Variable declarations at top of scope
    uint32_t result;

    if (A + B == C || A + C == B || B + C == A) {
        result = 1;
        //@ assert result == 1 ==> (A + B == C || A + C == B || B + C == A);
        return result;
    } else if (A + B > C && A + C > B && B + C > A) {
        //@ assert A + B > C && A + C > B && B + C > A;
        result = 2;
        //@ assert result == 2 ==> (A + B > C && A + C > B && B + C > A);
        return result;
    } else {
        result = 3;
        //@ assert result == 3 ==> (A + B <= C || A + C <= B || B + C <= A);
        return result;
    }
}
