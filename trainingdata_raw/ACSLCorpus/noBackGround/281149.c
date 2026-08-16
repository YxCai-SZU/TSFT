#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    int32_t temp;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    temp = c - (a - b);
    
    //@ assert temp == c - (a - b);
    
    if (temp < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = temp;
        //@ assert result == c - (a - b);
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;
    
    return result;
}
