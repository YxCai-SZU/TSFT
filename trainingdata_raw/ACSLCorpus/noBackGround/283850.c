#include <stdbool.h>

/*@
    requires (1 <= (A) <= 9);
    requires (1 <= (B) <= 9);
    requires (1 <= (C) <= 9);
    ensures \result == ((A == B && A != C) || (A != B && A == C) || (A != B && B == C));
*/
bool func(int A, int B, int C)
{
    //@ assert (1 <= (A) <= 9);
    //@ assert (1 <= (B) <= 9);
    //@ assert (1 <= (C) <= 9);
    return (A == B && A != C) || (A != B && A == C) || (A != B && B == C);
}
