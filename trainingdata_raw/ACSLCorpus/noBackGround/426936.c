#include <stdint.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures ((A) == (B) && (B) != (C)) ==> \result == C;
    ensures ((B) == (C) && (A) != (B)) ==> \result == A;
    ensures ((C) == (A) && (B) != (C)) ==> \result == B;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t result;

    //@ assert -100 <= A <= 100;
    //@ assert -100 <= B <= 100;
    //@ assert -100 <= C <= 100;

    if (A == B && A != C)
    {
        //@ assert ((A) == (B) && (B) != (C));
        result = C;
        return result;
    }
    else if (B == C && A != B)
    {
        //@ assert ((B) == (C) && (A) != (B));
        result = A;
        return result;
    }
    else if (C == A && B != C)
    {
        //@ assert ((C) == (A) && (B) != (C));
        result = B;
        return result;
    }

    result = 0;
    return result;
}
