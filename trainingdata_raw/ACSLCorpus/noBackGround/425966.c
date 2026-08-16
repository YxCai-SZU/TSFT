#include <limits.h>

/*@
    requires (1 <= (B) <= (A) <= 20 && 1 <= (C) <= 20);
    ensures \result >= 0 && \result <= C;
    ensures \result == C - (((C) < ((A) - (B))) ? (C) : ((A) - (B))) || \result == 0;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    // Variable declarations at scope top
    int min_val;
    int result;
    
    // Precondition verification
    //@ assert 1 <= B && B <= A && A <= 20;
    //@ assert 1 <= C && C <= 20;
    //@ assert A - B >= 0;
    
    // Compute min_val
    if (C < (A - B))
    {
        min_val = C;
    }
    else
    {
        min_val = A - B;
    }
    
    // Compute result
    if (min_val < 0)
    {
        result = 0;
    }
    else
    {
        result = C - min_val;
    }
    
    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= C;
    //@ assert result == C - min_val || result == 0;
    
    return result;
}
