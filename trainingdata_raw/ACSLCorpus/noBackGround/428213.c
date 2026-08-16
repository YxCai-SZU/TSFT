#include <stdint.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures (A == B && B != C) ==> \result == C;
    ensures (B == C && A != B) ==> \result == A;
    ensures (A == C && A != B) ==> \result == B;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;

    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-100 <= (C) <= 100);

    if (A == B) {
        ans = C;
    } else if (B == C) {
        ans = A;
    } else {
        ans = B;
    }

    //@ assert ans == C || ans == A || ans == B;

    return ans;
}
