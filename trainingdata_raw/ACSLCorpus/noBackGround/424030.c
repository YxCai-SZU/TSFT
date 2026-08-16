#include <stdint.h>
#include <stdbool.h>

/*@
    requires 2 <= N <= 100000;
    requires \valid(A + (0..N-1));
    requires ((N) >= 2 && (N) <= 100000 &&
    \forall integer i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= 10000);
    ensures \result >= 0;
    ensures \result <= N * 10000;
    assigns \nothing;
*/
int64_t func(uint32_t N, int64_t *A)
{
    int64_t ans = 0;
    uint32_t i = 0;
    int64_t X = 0;
    
    /*@
        loop invariant (0 <= (i) <= (N) &&
    (((N)) >= 2 && ((N)) <= 100000 &&
    \forall integer i; 0 <= i < ((N)) ==> ((A))[i] >= 1 && ((A))[i] <= 10000) &&
    (X) >= 0 &&
    (ans) >= 0 &&
    (X) <= (i) * 10000 &&
    (ans) <= (i) * 10000 &&
    (ans) >= (X));
        loop assigns i, X, ans;
        loop variant N - i;
    */
    while (i < N)
    {
        int64_t Ai = A[i];
        
        //@ assert Ai >= 1 && Ai <= 10000;
        
        // Simulate min: X = min(X, X + Ai)
        if (X + Ai < X)
        {
            X = X + Ai;
        }
        
        // Simulate max: ans = max(ans, ans + Ai)
        if (ans + Ai < ans)
        {
            ans = ans + Ai;
        }
        
        i++;
        
        //@ assert X >= 0;
        //@ assert ans >= 0;
        //@ assert X <= i * 10000;
        //@ assert ans <= i * 10000;
        //@ assert ans >= X;
    }
    
    //@ assert ans >= X;
    return ans - X;
}
