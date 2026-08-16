#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == ((A == B + 1 && B == C + 1) || (A == C + 2 && C == B + 1) || (A == B + 2 && B == C + 1));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;

    if ((A == B + 1 && B == C + 1) || (A == C + 2 && C == B + 1) || (A == B + 2 && B == C + 1))
    {
        result = true;
    }
    else
    {
        //@ assert !(A == B + 1 && B == C + 1) && !(A == C + 2 && C == B + 1) && !(A == B + 2 && B == C + 1);
        result = false;
    }

    return result;
}
