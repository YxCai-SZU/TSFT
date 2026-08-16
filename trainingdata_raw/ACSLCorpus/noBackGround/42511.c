#include <stdint.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    
    if (c > (a - b))
    {
        result = c - (a - b);
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == c - (a - b) || result == 0;
    //@ assert 0 <= result <= c;
    
    return result;
}
