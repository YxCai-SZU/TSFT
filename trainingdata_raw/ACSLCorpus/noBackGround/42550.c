#include <stdint.h>

/*@
    requires 0 <= a <= 4500;
    requires 0 <= b <= 4500;
    ensures \result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert 0 <= a <= 4500;
    //@ assert 0 <= b <= 4500;
    
    if (a > b * 2)
    {
        //@ assert ((a) > (b) * 2);
        result = a - b * 2;
        //@ assert result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    }
    else
    {
        //@ assert !((a) > (b) * 2);
        result = 0;
        //@ assert result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    }
    
    return result;
}
