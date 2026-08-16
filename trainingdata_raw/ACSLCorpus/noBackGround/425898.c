#include <stdbool.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures ((A) == (B) && (B) == (C)) ==> \result == 1;
    ensures ((A) != (B) && (B) != (C) && (C) != (A)) ==> \result == 0;
    ensures (((A) == (B) || (B) == (C) || (C) == (A)) && !((A) == (B) && (B) == (C))) ==> \result == 2;
*/
int func(int A, int B, int C)
{
    int count = 0;

    //@ assert (((A) == (B) ? 1 : 0) + ((B) == (C) ? 1 : 0) + ((C) == (A) ? 1 : 0)) == (A == B ? 1 : 0) + (B == C ? 1 : 0) + (C == A ? 1 : 0);

    if (A == B)
    {
        count += 1;
        //@ assert count == (A == B ? 1 : 0);
    }
    if (B == C)
    {
        count += 1;
        //@ assert count == (A == B ? 1 : 0) + (B == C ? 1 : 0);
    }
    if (C == A)
    {
        count += 1;
        //@ assert count == (((A) == (B) ? 1 : 0) + ((B) == (C) ? 1 : 0) + ((C) == (A) ? 1 : 0));
    }

    //@ assert count == (((A) == (B) ? 1 : 0) + ((B) == (C) ? 1 : 0) + ((C) == (A) ? 1 : 0));

    if (count == 3)
    {
        //@ assert ((A) == (B) && (B) == (C));
        return 1;
    }
    else if (count == 1 || count == 2)
    {
        //@ assert (((A) == (B) || (B) == (C) || (C) == (A)) && !((A) == (B) && (B) == (C)));
        return 2;
    }
    else
    {
        //@ assert count == 0;
        //@ assert ((A) != (B) && (B) != (C) && (C) != (A));
        return 0;
    }
}
