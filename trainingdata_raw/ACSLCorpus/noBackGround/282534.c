#include <stdint.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == ((C) - ((A) - (B))) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t remain;
    int64_t result;

    //@ assert (1 <= (B) && (B) <= (A) && (A) <= 20 &&         1 <= (C) && (C) <= 20);
    remain = C - (A - B);
    
    //@ assert remain == ((C) - ((A) - (B)));
    
    if (remain < 0)
    {
        result = 0;
    }
    else
    {
        result = remain;
    }
    
    //@ assert result == ((((C)) - (((A)) - ((B)))) < 0 ? 0 : (((C)) - (((A)) - ((B)))));
    //@ assert result >= 0;
    //@ assert result <= C;
    //@ assert result == ((C) - ((A) - (B))) || result == 0;
    
    return result;
}
