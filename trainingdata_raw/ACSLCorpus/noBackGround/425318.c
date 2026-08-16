#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == (A + B == C || A + C == B || B + C == A);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at top
    bool result;

    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    //@ assert A + B <= 200;
    //@ assert A + C <= 200;
    //@ assert B + C <= 200;

    result = (A + B == C) || (A + C == B) || (B + C == A);
    return result;
}
