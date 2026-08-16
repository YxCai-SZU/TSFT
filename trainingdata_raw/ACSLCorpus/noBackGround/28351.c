#include <stdint.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == (((a) - (b) <= (c)) ? ((c) - ((a) - (b))) : 0);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    int32_t temp;

    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    
    result = a - b;
    
    //@ assert result == a - b;
    
    temp = result;
    if (temp < c) {
        //@ assert temp < c;
        result = temp;
    } else {
        //@ assert temp >= c;
        result = c;
    }
    
    //@ assert result <= c;
    
    result = c - result;
    
    //@ assert result >= 0;
    
    //@ assert result <= c;
    
    //@ assert result == (((a) - (b) <= (c)) ? ((c) - ((a) - (b))) : 0);
    
    return result;
}
