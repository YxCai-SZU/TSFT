#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (a < 10 && b < 10 ==> \result == (int)(a * b)) &&
            (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_val;
    int32_t result;
    
    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    
    max_val = (a > b) ? a : b;
    
    //@ assert 1 <= max_val <= 20;
    
    if (max_val < 10)
    {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
        //@ assert result == (int)(a * b);
    }
    else
    {
        //@ assert a >= 10 || b >= 10;
        result = -1;
    }
    
    return result;
}
