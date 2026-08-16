#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == true <==> ((A) + (B) == (C) || (B) + (C) == (A) || (A) + (C) == (B));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    if (A + B == C || B + C == A || A + C == B) {
        result = true;
        //@ assert ((A) + (B) == (C) || (B) + (C) == (A) || (A) + (C) == (B));
    } else {
        result = false;
        //@ assert !((A) + (B) == (C) || (B) + (C) == (A) || (A) + (C) == (B));
    }
    
    return result;
}
