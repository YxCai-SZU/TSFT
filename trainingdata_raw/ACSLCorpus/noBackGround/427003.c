#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (c - (a - b) <= 0) ==> \result == 0;
    ensures (c - (a - b) >= 1) ==> \result == c - (a - b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    int32_t intermediate;

    //@ assert a - b >= 0;
    intermediate = a - b;
    
    //@ assert c - intermediate <= 20;
    result = c - intermediate;
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert (c - (a - b) <= 0) ==> result == 0;
    //@ assert (c - (a - b) >= 1) ==> result == c - (a - b);
    
    return result;
}
