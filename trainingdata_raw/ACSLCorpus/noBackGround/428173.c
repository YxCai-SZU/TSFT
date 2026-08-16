#include <stdint.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    int32_t diff;
    int32_t result;

    diff = A - B;
    
    if (C > diff)
    {
        //@ assert C - diff >= 0;
        //@ assert C - diff <= C;
        result = C - diff;
    }
    else
    {
        result = 0;
    }

    return result;
}
