#include <stdint.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t result;
    
    //@ assert A >= B;
    //@ assert A - B <= 20;
    
    if (C > (A - B))
    {
        result = C - (A - B);
    }
    else
    {
        result = 0;
    }
    
    return result;
}
