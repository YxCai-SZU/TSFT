#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == true <==> (((A) <= (C) && (C) <= (B)) || ((A) >= (C) && (C) >= (B)));
    assigns \nothing;
 */
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int max;
    unsigned int min;
    bool result;

    if (A > B)
    {
        max = A;
    }
    else
    {
        max = B;
    }

    if (A < B)
    {
        min = A;
    }
    else
    {
        min = B;
    }

    //@ assert max == A || max == B;
    //@ assert min == A || min == B;
    //@ assert max >= min;

    if (C <= max && C >= min)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (((A) <= (C) && (C) <= (B)) || ((A) >= (C) && (C) >= (B)));
    return result;
}
