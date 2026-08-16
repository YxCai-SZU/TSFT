#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A * B || \result == C * D;
    ensures 1 <= \result <= 10000 * 10000;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int ans;
    
    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    //@ assert 1 <= A * B <= 10000 * 10000;
    
    //@ assert (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    //@ assert 1 <= C * D <= 10000 * 10000;
    
    if (A * B > C * D) {
        ans = A * B;
    } else {
        ans = C * D;
    }
    
    //@ assert ans == A * B || ans == C * D;
    //@ assert 1 <= ans <= 10000 * 10000;
    
    return ans;
}
