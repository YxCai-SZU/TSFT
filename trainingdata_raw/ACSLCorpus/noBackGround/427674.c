#include <stdint.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100);
    ensures (A == B && A != C) ==> \result == C;
    ensures (A != B && A == C) ==> \result == B;
    ensures (A == C && A != B) ==> \result == B;
    ensures (A == B && A == C) ==> \result == A;
    ensures (A != B && B == C) ==> \result == A;
    ensures \result == A || \result == B || \result == C;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;
    
    //@ assert (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100);
    
    if (A == B && A != C) {
        ans = C;
        //@ assert (A == B && A != C) ==> ans == C;
    } else if (A != B && A == C) {
        ans = B;
        //@ assert (A != B && A == C) ==> ans == B;
    } else {
        ans = A;
        //@ assert (A == C && A != B) ==> ans == B;
    }
    
    //@ assert (A == B && A == C) ==> ans == A;
    //@ assert (A != B && B == C) ==> ans == A;
    //@ assert ans == A || ans == B || ans == C;
    
    return ans;
}
