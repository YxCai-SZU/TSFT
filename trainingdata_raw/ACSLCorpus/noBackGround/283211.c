#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= h <= 100;
    requires h % 2 == 0;
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    uint32_t result;
    
    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;
    //@ assert ((a + b) * h) % 2 == 0;
    
    result = (a + b) * h / 2;
    
    //@ assert result == (a + b) * h / 2;
    return result;
}
