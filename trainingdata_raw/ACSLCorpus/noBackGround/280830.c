#include <stdbool.h>

/*@
    requires (1 <= (A) <= 9) && (1 <= (B) <= 9) && (1 <= (C) <= 9);
    ensures \result == true <==> (((A) == (B) && (B) != (C)) ||
        ((B) == (C) && (B) != (A)) ||
        ((A) == (C) && (A) != (B)));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    //@ assert (1 <= (A) <= 9);
    //@ assert (1 <= (B) <= 9);
    //@ assert (1 <= (C) <= 9);
    
    return (A == B && B != C) || (B == C && B != A) || (A == C && A != B);
}
