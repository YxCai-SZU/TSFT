#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100);
    ensures \result <= C;
    ensures \result <= B / A;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    uint32_t result;

    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100 &&         1 <= (C) && (C) <= 100);
    result = B / A;

    if (C < result)
    {
        result = C;
        //@ assert result <= C;
    }
    else
    {
        //@ assert result <= B / A;
    }

    //@ assert result <= C;
    //@ assert result <= B / A;
    return result;
}
