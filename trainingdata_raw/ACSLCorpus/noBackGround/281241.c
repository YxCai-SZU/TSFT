#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int AB;
    int CD;
    int ans;
    
    //@ assert A > 0 && A <= 10000;
    //@ assert B > 0 && B <= 10000;
    //@ assert A * B <= 10000 * 10000;
    AB = A * B;
    
    //@ assert C > 0 && C <= 10000;
    //@ assert D > 0 && D <= 10000;
    //@ assert C * D <= 10000 * 10000;
    CD = C * D;
    
    //@ assert AB == A * B && CD == C * D;
    
    if (AB > CD) {
        ans = AB;
    } else {
        ans = CD;
    }
    
    //@ assert ans == ((AB) > (CD) ? (AB) : (CD));
    //@ assert ans == A * B || ans == C * D;
    //@ assert ans >= A * B && ans >= C * D;
    
    return ans;
}
