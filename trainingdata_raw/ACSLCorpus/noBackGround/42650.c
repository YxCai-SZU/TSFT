#include <limits.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result == 1 ==> (A == B && B == C);
    ensures \result == 2 ==> ((A == B || A == C || B == C) && !(A == B && B == C));
    ensures \result == 3 ==> (A != B && A != C && B != C);
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int result;

    //@ assert (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);

    if (A == B && B == C)
    {
        result = 1;
        //@ assert result == 1 && A == B && B == C;
        return result;
    }
    else if (A == B || A == C || B == C)
    {
        result = 2;
        //@ assert result == 2 && (A == B || A == C || B == C) && !(A == B && B == C);
        return result;
    }
    else
    {
        result = 3;
        //@ assert result == 3 && A != B && A != C && B != C;
        return result;
    }
}
