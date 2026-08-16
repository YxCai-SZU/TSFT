#include <stdint.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures ((A) == (B) && (B) == (C)) ==> \result == 1;
    ensures (((A) == (B) && (B) != (C)) ||
        ((A) == (C) && (C) != (B)) ||
        ((B) == (C) && (C) != (A))) ==> \result == 2;
    ensures ((A) != (B) && (B) != (C) && (C) != (A)) ==> \result == 3;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t result;

    if (A == B)
    {
        if (B == C)
        {
            result = 1;
            //@ assert ((A) == (B) && (B) == (C));
            return result;
        }
        else
        {
            result = 2;
            //@ assert A == B && B != C;
            return result;
        }
    }
    else if (A == C)
    {
        result = 2;
        //@ assert A == C && C != B;
        return result;
    }
    else if (B == C)
    {
        result = 2;
        //@ assert B == C && C != A;
        return result;
    }
    else
    {
        result = 3;
        //@ assert A != B && B != C && C != A;
        return result;
    }
}
