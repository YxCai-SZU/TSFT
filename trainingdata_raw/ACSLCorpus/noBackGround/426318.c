#include <stdbool.h>

/*@
    requires 1 <= A <= 10;
    requires 1 <= B <= 10;
    requires 1 <= C <= 10;
    ensures \result == (A == B && B == C);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    //@ assert 1 <= A <= 10;
    //@ assert 1 <= B <= 10;
    //@ assert 1 <= C <= 10;
    //@ assert (A == B && B == C) ==> (A == B && B == C);
    //@ assert (A != B || B != C) || (A == B && B == C);
    return A == B && B == C;
}
