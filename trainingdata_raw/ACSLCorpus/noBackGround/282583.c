#include <stdint.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == (((A) - (B) > (C)) ? 0 : ((C) - ((A) - (B))));
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t remain;
    int64_t result;
    
    remain = A - B;
    
    if (remain > C) {
        result = 0;
        //@ assert result == 0;
    } else {
        //@ assert remain <= C;
        result = C - remain;
        //@ assert result == C - remain;
    }
    
    //@ assert result == (((A) - (B) > (C)) ? 0 : ((C) - ((A) - (B))));
    return result;
}
