#include <stdint.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ((A) == (B) && (B) == (C));
    ensures \result == 2 ==> (((A) == (B) && (B) != (C)) || ((B) == (C) && (A) != (B)) || ((A) == (C) && (B) != (A)));
    ensures \result == 3 ==> ((A) != (B) && (B) != (C) && (A) != (C));
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    int32_t result;

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;

    if (A == B && B == C)
    {
        //@ assert ((A) == (B) && (B) == (C));
        result = 1;
    }
    else if (A == B || B == C || A == C)
    {
        //@ assert (((A) == (B) && (B) != (C)) || ((B) == (C) && (A) != (B)) || ((A) == (C) && (B) != (A)));
        result = 2;
    }
    else
    {
        //@ assert ((A) != (B) && (B) != (C) && (A) != (C));
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}
