#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_local = a;
    uint32_t b_local = b;
    uint32_t sum = 0;
    int32_t result = 0;
    
    //@ assert a_local <= 100;
    //@ assert b_local <= 100;
    
    sum = a_local + b_local;
    //@ assert sum <= 200;
    
    if (a_local % 3 == 0 || b_local % 3 == 0 || sum % 3 == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    return result;
}
