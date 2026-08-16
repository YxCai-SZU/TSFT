#include <limits.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
*/
int func(int A, int B, int C)
{
    int ans;

    //@ assert (1 <= (B) && (B) <= (A) && (A) <= 20 &&         1 <= (C) && (C) <= 20);
    ans = C - (A - B);
    
    if (ans < 0)
    {
        //@ assert ans < 0;
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        //@ assert ans >= 0;
        //@ assert ans == C - (A - B);
    }

    //@ assert ans >= 0;
    //@ assert ans <= C;
    //@ assert ans == C - (A - B) || ans == 0;
    return ans;
}
