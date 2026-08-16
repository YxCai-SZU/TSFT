#include <stdint.h>

/*@
    requires 1 <= a && a <= 20;
    requires 1 <= b && b <= 20;
    ensures (a < 10 && b < 10 ==> \result == (int)(a * b)) &&
            (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    uint32_t a_is_small;
    uint32_t b_is_small;
    
    a_is_small = (a < 10);
    b_is_small = (b < 10);
    
    if (a_is_small && b_is_small)
    {
        //@ assert 1 <= a && a <= 9;
        //@ assert 1 <= b && b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    }
    else
    {
        result = -1;
    }
    
    return result;
}
