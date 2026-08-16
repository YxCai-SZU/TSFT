#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == true <==> ((A) + (B) == (C) || (A) + (C) == (B) || (B) + (C) == (A));
    assigns \nothing;
 */
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int AB;
    unsigned int BC;
    unsigned int CA;
    bool result;

    AB = A + B;
    BC = B + C;
    CA = C + A;

    //@ assert AB <= 200;
    //@ assert BC <= 200;
    //@ assert CA <= 200;

    if (AB == C || BC == A || CA == B)
    {
        result = true;
    }
    else
    {
        //@ assert AB != C && BC != A && CA != B;
        result = false;
    }

    return result;
}
