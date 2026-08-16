#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20);
    ensures \result >= (((b) - 1 + (a) - 2) / ((a) - 1));
    ensures \result * (a - 1) >= b - 1;
    ensures \result * (a - 1) < b + a - 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Declare all variables at the top
    uint32_t result;
    uint32_t temp1;
    uint32_t temp2;
    uint32_t temp3;

    //@ assert a >= 2 && a <= 20;
    //@ assert b >= 1 && b <= 20;
    
    //@ assert a - 1 >= 1;
    temp1 = b - 1;
    temp2 = a - 2;
    temp3 = a - 1;
    
    //@ assert temp1 + temp2 >= 0;
    //@ assert temp3 > 0;
    
    result = (temp1 + temp2) / temp3;
    
    //@ assert result * (a - 1) >= b - 1;
    //@ assert result * (a - 1) < b + a - 1;
    
    return result;
}
